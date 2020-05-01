#pragma once
#include <map>
#include <thread>
#include <winsock2.h>
#include "LoginRequestHandler.h"

#define PORT 2223

class Communicator
{
private:
	std::map<SOCKET, IRequestHandler*> m_clients;
	SOCKET _socket;


	void bindAndListen();
	void handleNewClient();
public:
	Communicator();
	~Communicator();
	void startHandleRequests();
};

