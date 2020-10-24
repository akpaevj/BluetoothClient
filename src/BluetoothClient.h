#pragma once

#include <string>
#include <WinSock2.h>
#include <ws2bth.h>
#include <initguid.h>
#include "Component.h"

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

#define INITGUID

// {00001101-0000-1000-8000-00805f9b34fb}
DEFINE_GUID(g_sppServer, 0x00001101, 0x0000, 0x1000, 0x80, 0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb);

// {8ce255c0-200a-11e0-ac64-0800200c9a66}
DEFINE_GUID(g_insecureBluetoothClientChat, 0x8ce255c0, 0x200a, 0x11e0, 0xac, 0x64, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66);

class BluetoothClient final : public Component
{
public:
	const char *Version = u8"1.0.0";
	BluetoothClient();
private:
	std::string extensionName() override;
	void Open(const variant_t deviceName);
	void Write(const variant_t message);
	variant_t Read();
	variant_t Opened();
	void Close();
	SOCKET localSocket = NULL;
	ULONG NameToBluetoothAddress(const wstring deviceName, PSOCKADDR_BTH pRemoteBtAddr);
	string GetWsaErrorMessage();

	bool _opened = false;

	shared_ptr<variant_t> timeoutProperty;

	BluetoothClient operator=(const BluetoothClient&) = delete;
};
