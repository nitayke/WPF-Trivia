#include "Communicator.h"

void Communicator::bindAndListen()
{
    struct sockaddr_in sa = { 0 };
	sa.sin_port = htons(PORT);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = 0;
	// again stepping out to the global namespace
	if (::bind(_socket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");
	printf("binded\n");

	if (::listen(_socket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	printf("listening...\n");
}

void Communicator::handleNewClient(SOCKET client_socket)
{
	IRequestHandler* handler; 
	RequestInfo ri;
	RequestResult result;
	Buffer tmp;
	char buffer[1024];
	while (true)
	{                           
		handler = m_clients[client_socket];
		int res = recv(client_socket, buffer, 1024, 0);
		if (res == INVALID_SOCKET)
		{
			throw std::exception("Error while recieving from socket");
		}
		time(&ri.receivalTime);
		for (size_t i = 0; i < 1024 && buffer[i] != '\0'; i++)
		{
			tmp.push_back((byte)buffer[i]);
		}
		if (!handler->isRequestRelevant(ri))
		{
			return;
		}
		result = handler->handleRequest(ri);
		
		ri.id = tmp[0];
		LoginRequest req = JsonRequestPacketDeserializer::deserializeLoginRequest(tmp);
		for (size_t i = 5; i < tmp.size(); i++)
		{
			ri.buffer.push_back(tmp[i]);
		}
		printf(buffer); // send the buffer 
		if (send(client_socket, buffer, 5, 0) == INVALID_SOCKET) //change the object that we send
			throw std::exception("Error while sending message to client");
		// set the map to the new IRequestHandler* handler from the RequestResult 
	}
}

Communicator::Communicator()
{
	_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Communicator::~Communicator()
{
	try
	{
		::closesocket(_socket);
	}
	catch (...) {}
}

void Communicator::startHandleRequests()
{
	bindAndListen();

	while (true)
	{
		SOCKET client_socket = accept(_socket, NULL, NULL);
		if (client_socket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__);

		printf("Client accepted !\n");
		// create new thread for client	and detach from it
		std::thread tr(&Communicator::handleNewClient, this, client_socket);
		tr.detach();

		this->m_clients.insert(std::pair<SOCKET, IRequestHandler*>(client_socket, new LoginRequestHandler()));
	}
}
