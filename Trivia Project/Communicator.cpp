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

void Communicator::handleNewClient() // we have to implement this function
{
	char buffer[6] = { 0 };
	send(_socket, "Hello", 5, 0);
	recv(_socket, buffer, 5, 0);
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
		std::thread tr(&Communicator::handleNewClient, this);
		tr.detach();

		this->m_clients.insert(std::pair<SOCKET, IRequestHandler*>(client_socket, new LoginRequestHandler()));
		// we need to replace the null by LoginRequest or something

	}
}
