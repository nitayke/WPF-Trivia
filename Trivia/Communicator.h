#pragma once
#include <map>
#include <thread>
#include <winsock2.h>
#include "LoginRequestHandler.h"
#include "HandlersStructs.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"

#define PORT 2222

class Communicator
{
private:
	std::map<SOCKET, IRequestHandler*> m_clients;
	SOCKET _socket;

	void handleNewClient(SOCKET socket);
public:
	Communicator();
	~Communicator();
	void startHandleRequests();
	void bindAndListen();
};

