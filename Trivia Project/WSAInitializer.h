#pragma comment(lib,"ws2_32")

#include <WinSock2.h>
#include <Windows.h>
#include <exception>


class WSAInitializer
{
public:
	WSAInitializer();
	~WSAInitializer();
};

