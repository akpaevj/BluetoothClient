#include "BluetoothClient.h"
#include <locale>
#include <codecvt>
#include <algorithm>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

std::string BluetoothClient::extensionName() {
    return "BluetoothClient";
}

BluetoothClient::BluetoothClient(){

    timeoutProperty = make_shared<variant_t>(0);
    AddProperty(L"Timeout", L"Таймаут", timeoutProperty);

    AddProperty(L"Version", L"ВерсияКомпоненты", [&]() {
        auto s = std::string(Version);
        return std::make_shared<variant_t>(std::move(s));
    });

    debugMode = make_shared<variant_t>(false);
    AddProperty(L"DebugMode", L"РежимОтладки", debugMode);

    AddMethod(L"Open", L"Открыть", this, &BluetoothClient::Open);
    AddMethod(L"Write", L"Записать", this, &BluetoothClient::Write);
    AddMethod(L"Opened", L"Открыто", this, &BluetoothClient::Opened);
    AddMethod(L"Read", L"Прочитать", this, &BluetoothClient::Read);
    AddMethod(L"Close", L"Закрыть", this, &BluetoothClient::Close);
}

BluetoothClient::~BluetoothClient() {
    Close();
}

void BluetoothClient::Open(const variant_t deviceName)
{
    if (_opened) {
        AddError(ADDIN_E_VERY_IMPORTANT, extensionName(), "Connection is already opened", true);
        return;
    }

	WSADATA wsaData;

    auto sdeviceName = get<string>(deviceName);
    AddDebugMessage("INFO: Starting connection to the device named \"" + sdeviceName + "\"");

    wstring wdeviceName(sdeviceName.begin(), sdeviceName.end());

    SOCKADDR_BTH RemoteBthAddr = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        AddError(ADDIN_E_VERY_IMPORTANT, extensionName(), "Unable to initialize Winsock version 2.2", true);
        return;
	}

    if (NameToBluetoothAddress(wdeviceName, &RemoteBthAddr) != 0) {
        WSACleanup();
        AddError(ADDIN_E_VERY_IMPORTANT, extensionName(), "Не удалось получить адрес или устройство недоступно (" + sdeviceName + ")", true);
        return;
    }

    localSocket = socket(AF_BTH, SOCK_STREAM, BTHPROTO_RFCOMM);

    auto t_val = get<int>(*timeoutProperty);
    AddDebugMessage("INFO: Timeout is " + to_string(t_val));

    int timeoutValMs = t_val * 1000;

    if (timeoutValMs > 0) {
        setsockopt(localSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeoutValMs, sizeof(timeoutValMs));
        setsockopt(localSocket, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeoutValMs, sizeof(timeoutValMs));
    }

    if (INVALID_SOCKET == localSocket) {
        auto err = GetWsaErrorMessage();
        WSACleanup();
        AddError(ADDIN_E_VERY_IMPORTANT, extensionName(), err, true);
        return;
    }

    SOCKADDR_BTH SockAddrBthServer = RemoteBthAddr;

    SockAddrBthServer.addressFamily = AF_BTH;
    SockAddrBthServer.serviceClassId = g_insecureBluetoothClientChat;
    SockAddrBthServer.port = 0;

    if (SOCKET_ERROR == connect(localSocket, (const sockaddr*)&SockAddrBthServer, sizeof(SOCKADDR_BTH))) {
        auto err = GetWsaErrorMessage();
        WSACleanup();
        AddError(ADDIN_E_VERY_IMPORTANT, extensionName(), err, true);
        return;
    }
    else {
        _opened = true;
    }
}

void BluetoothClient::Write(const variant_t message)
{
    if (!_opened) {
        AddError(ADDIN_E_VERY_IMPORTANT, extensionName(), "You should open a connection before writing any data", true);
        return;
    }

    auto msg = get<string>(message);
    
    msg.push_back(ETX);
    auto lrc = CalculateLrc(msg);
    msg.insert(0, 1, STX);
    msg += lrc;

    auto data = msg.c_str();

    if (SOCKET_ERROR == send(localSocket, data, msg.length(), 0)) {
        AddError(ADDIN_E_FAIL, extensionName(), GetWsaErrorMessage(), true);
    }
}

void BluetoothClient::SendNak() {
    char symb[] = { NAK };

    if (SOCKET_ERROR == send(localSocket, symb, 1, 0)) {
        AddError(ADDIN_E_FAIL, extensionName(), GetWsaErrorMessage(), true);
    }
}

void BluetoothClient::SendAck() {
    char symb[] = { ACK };

    if (SOCKET_ERROR == send(localSocket, symb, 1, 0)) {
        AddError(ADDIN_E_FAIL, extensionName(), GetWsaErrorMessage(), true);
    }
}

variant_t BluetoothClient::Read()
{
    if (!_opened) {
        AddError(ADDIN_E_VERY_IMPORTANT, extensionName(), "You should open a connection before reading any data", true);
        return "";
    }

    string message = "";
    const int bLength = 1000;
    char buffer[bLength];
    int tries = 0;
    bool messageStarted = false;
    char calcLrc = 0;

    while (true) {
        // For avoiding infinite loop stop it after 3 tries
        if (tries == 3) {
            AddError(ADDIN_E_FAIL, extensionName(), "Failed to get a message", true);
            return message;
        }

        int len = recv(localSocket, buffer, bLength, 0);
        
        if (len == SOCKET_ERROR) {
            AddError(ADDIN_E_FAIL, extensionName(), GetWsaErrorMessage(), true);
            break;
        }
        else if (len == 0)
            break;

        AddDebugMessage("INFO: Received " + to_string(len) + " bytes");

        // First byte of the message MUST be a STX symbol. If everything is ok, continue reading the stream
        if (!messageStarted) {
            if (buffer[0] == STX) {
                AddDebugMessage("INFO: Received STX symbol");
                messageStarted = true;
            }
            else if (buffer[0] == NAK) {
                AddError(ADDIN_E_FAIL, extensionName(), "Received NAK symbol, you should send the message again", true);
                return "";
            }
            else {
                AddError(ADDIN_E_FAIL, extensionName(), "The first byte of the stream is not a STX symbol", true);
                return message;
            }
        }

        for (int i = 0; i < len; i++) {
            auto c = buffer[i];

            // Calculate message checksum and push char to message string
            if (c != STX) {
                if (c != ETX)
                    message.push_back(c);

                calcLrc ^= c;
            }

            if (c == ETX) {
                AddDebugMessage("INFO: ETX symbol reached");

                auto receivedLrc = buffer[i + 1];
                AddDebugMessage("INFO: Received message LRC is " + to_string(receivedLrc));
                AddDebugMessage("INFO: Calculated message LRC is " + to_string(calcLrc));

                if (receivedLrc == calcLrc) {
                    AddDebugMessage("INFO: Calculated LRC and received one are the same");
                    // Send acknowledge and pass message to 1C
                    SendAck();
                    AddDebugMessage("INFO: ACK message sent");

                    return message;
                }
                else {
                    AddDebugMessage("WARNING: calculated LRC differs from received one. It'll send NAK symbol and read the message again");  
                    SendNak();
                    message.clear();
                    tries++;
                    messageStarted = false;
                    calcLrc = 0;

                    break;
                }
            }
        }
    }

    AddError(ADDIN_E_FAIL, extensionName(), "Failed to get a message", true);
    return "";
}

ULONG BluetoothClient::NameToBluetoothAddress(const wstring deviceName, PSOCKADDR_BTH pRemoteBtAddr)
{
    INT             iResult = 0;
    BOOL            bContinueLookup = FALSE, bRemoteDeviceFound = FALSE;
    ULONG           ulFlags = 0, ulPQSSize = sizeof(WSAQUERYSET);
    HANDLE          hLookup = NULL;
    PWSAQUERYSET    pWSAQuerySet = NULL;

    ZeroMemory(pRemoteBtAddr, sizeof(*pRemoteBtAddr));

    pWSAQuerySet = (PWSAQUERYSET)HeapAlloc(GetProcessHeap(),
        HEAP_ZERO_MEMORY,
        ulPQSSize);
    if (NULL == pWSAQuerySet) {
        iResult = STATUS_NO_MEMORY;
    }

    //
    // Search for the device with the correct name
    //
    if (iResult == 0) {

        for (INT iRetryCount = 0;
            !bRemoteDeviceFound && (iRetryCount < 3);
            iRetryCount++) {
            //
            // WSALookupService is used for both service search and device inquiry
            // LUP_CONTAINERS is the flag which signals that we're doing a device inquiry.
            //
            ulFlags = LUP_CONTAINERS;

            //
            // Friendly device name (if available) will be returned in lpszServiceInstanceName
            //
            ulFlags |= LUP_RETURN_NAME;

            //
            // BTH_ADDR will be returned in lpcsaBuffer member of WSAQUERYSET
            //
            ulFlags |= LUP_RETURN_ADDR;

            if (0 != iRetryCount) {
                //
                // Flush the device cache for all inquiries, except for the first inquiry
                //
                // By setting LUP_FLUSHCACHE flag, we're asking the lookup service to do
                // a fresh lookup instead of pulling the information from device cache.
                //
                ulFlags |= LUP_FLUSHCACHE;

                //
                // Pause for some time before all the inquiries after the first inquiry
                //
                // Remote Name requests will arrive after device inquiry has
                // completed.  Without a window to receive IN_RANGE notifications,
                // we don't have a direct mechanism to determine when remote
                // name requests have completed.
                //
                Sleep(15 * 1000);
            }

            //
            // Start the lookup service
            //
            iResult = 0;
            hLookup = 0;
            bContinueLookup = FALSE;
            ZeroMemory(pWSAQuerySet, ulPQSSize);
            pWSAQuerySet->dwNameSpace = NS_BTH;
            pWSAQuerySet->dwSize = sizeof(WSAQUERYSET);
            iResult = WSALookupServiceBegin(pWSAQuerySet, ulFlags, &hLookup);

            //
            // Even if we have an error, we want to continue until we
            // reach the CXN_MAX_INQUIRY_RETRY
            //
            if ((NO_ERROR == iResult) && (NULL != hLookup)) {
                bContinueLookup = TRUE;
            }
            else if (0 < iRetryCount) {
                break;
            }

            while (bContinueLookup) {
                //
                // Get information about next BluetoothClient device
                //
                // Note you may pass the same WSAQUERYSET from LookupBegin
                // as long as you don't need to modify any of the pointer
                // members of the structure, etc.
                //
                // ZeroMemory(pWSAQuerySet, ulPQSSize);
                // pWSAQuerySet->dwNameSpace = NS_BTH;
                // pWSAQuerySet->dwSize = sizeof(WSAQUERYSET);
                if (NO_ERROR == WSALookupServiceNext(hLookup,
                    ulFlags,
                    &ulPQSSize,
                    pWSAQuerySet)) {

                    //
                    // Compare the name to see if this is the device we are looking for.
                    //
                    if ((pWSAQuerySet->lpszServiceInstanceName != NULL) &&
                        (_wcsicmp(pWSAQuerySet->lpszServiceInstanceName, deviceName.c_str()) == 0)) {
                        //
                        // Found a remote BluetoothClient device with matching name.
                        // Get the address of the device and exit the lookup.
                        //
                        CopyMemory(pRemoteBtAddr,
                            (PSOCKADDR_BTH)pWSAQuerySet->lpcsaBuffer->RemoteAddr.lpSockaddr,
                            sizeof(*pRemoteBtAddr));
                        bRemoteDeviceFound = TRUE;
                        bContinueLookup = FALSE;
                    }
                }
                else {
                    iResult = WSAGetLastError();
                    if (WSA_E_NO_MORE == iResult) { //No more data
                        //
                        // No more devices found.  Exit the lookup.
                        //
                        bContinueLookup = FALSE;
                    }
                    else if (WSAEFAULT == iResult) {
                        //
                        // The buffer for QUERYSET was insufficient.
                        // In such case 3rd parameter "ulPQSSize" of function "WSALookupServiceNext()" receives
                        // the required size.  So we can use this parameter to reallocate memory for QUERYSET.
                        //
                        HeapFree(GetProcessHeap(), 0, pWSAQuerySet);
                        pWSAQuerySet = (PWSAQUERYSET)HeapAlloc(GetProcessHeap(),
                            HEAP_ZERO_MEMORY,
                            ulPQSSize);
                        if (NULL == pWSAQuerySet) {
                            iResult = STATUS_NO_MEMORY;
                            bContinueLookup = FALSE;
                        }
                    }
                    else {
                        bContinueLookup = FALSE;
                    }
                }
            }

            //
            // End the lookup service
            //
            WSALookupServiceEnd(hLookup);

            if (STATUS_NO_MEMORY == iResult) {
                break;
            }
        }
    }

    if (NULL != pWSAQuerySet) {
        HeapFree(GetProcessHeap(), 0, pWSAQuerySet);
        pWSAQuerySet = NULL;
    }

    if (bRemoteDeviceFound) {
        iResult = 0;
    }
    else {
        iResult = 1;
    }

    return iResult;
}

string BluetoothClient::GetWsaErrorMessage()
{
    wchar_t* s;

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, WSAGetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPWSTR)&s, 0, NULL);

    auto ss = Component::toUTF8String(s);

    LocalFree(s);

    return ss;
}

char BluetoothClient::CalculateLrc(string message) {
    char LRC = 0;
    for (int i = 0; i < message.length(); i++) {
        LRC ^= message[i];
    }
    return LRC;
}

void BluetoothClient::AddDebugMessage(string message) {
    auto write = get<bool>(*debugMode);

    if (write) {
        AddError(ADDIN_E_INFO, extensionName(), message, false);
    }
}

variant_t BluetoothClient::Opened() 
{
    return _opened;
}

void BluetoothClient::Close()
{
    if (localSocket != INVALID_SOCKET && _opened) {
        if (SOCKET_ERROR == closesocket(localSocket)) {
            auto err = GetWsaErrorMessage();
            WSACleanup();
            localSocket = INVALID_SOCKET;
            AddError(ADDIN_E_FAIL, extensionName(), err, true);
        }
        else {
            WSACleanup();
            localSocket = INVALID_SOCKET;
        }

        _opened = false;

        AddDebugMessage("INFO: Disconnected");
    }
}