#pragma once

#include <string>
#include <WinSock2.h>
#include <ws2bth.h>
#include <initguid.h>
#include "Component.h"

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

#define INITGUID

// {8ce255c0-200a-11e0-ac64-0800200c9a66}
DEFINE_GUID(g_insecureBluetoothClientChat, 0x8ce255c0, 0x200a, 0x11e0, 0xac, 0x64, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66);

class BluetoothClient final : public Component
{
public:
	const char *Version = u8"1.1.4";
	BluetoothClient();
	~BluetoothClient();
private:
	// Control symbols
	const char SOH = 0x01; // start of heading
	const char STX = 0x02; // start of text
	const char ETX = 0x03; // end of text
	const char EOT = 0x04; // end of transmission
	const char ENQ = 0x05; // enquiry
	const char ACK = 0x06; // acknowledge
	const char CR = 0x0D; // carriage return
	const char NAK = 0x15; // negative acknowledge

	std::string extensionName() override;
	void Open(const variant_t deviceName);
	void Write(const variant_t message);
	variant_t Read();
	variant_t Opened();
	void Close();
	SOCKET localSocket = INVALID_SOCKET;
	ULONG NameToBluetoothAddress(const wstring deviceName, PSOCKADDR_BTH pRemoteBtAddr);
	string GetWsaErrorMessage();
	char CalculateLrc(string message);
	void SendNak();
	void SendAck();
	void AddDebugMessage(string message);

	bool opened = false;
	std::shared_ptr<variant_t> timeoutProperty;
	std::shared_ptr<variant_t> debugMode;

	BluetoothClient operator=(const BluetoothClient&) = delete;
};
