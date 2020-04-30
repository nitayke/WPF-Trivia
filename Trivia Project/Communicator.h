#pragma once
#include <map>
#include <WinSock2.h>
#include "IRequestHandler.h"

class Communicator
{
private:
	std::map<SOCKET, IRequestHandler*> m_clients;


	void bindAndListen();
	void handleNewClient();
public:
	void startHandleRequests();
};

