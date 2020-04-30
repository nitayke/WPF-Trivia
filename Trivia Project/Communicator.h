#pragma once
#include <map>
#include <WinSock2.h>
#include <thread>
#include <iostream>
#include "IRequestHandler.h"

#define PORT 2222

class Communicator
{
private:
	std::map<SOCKET, IRequestHandler*> m_clients;


	void bindAndListen();
	void handleNewClient();
public:
	void startHandleRequests();
};

