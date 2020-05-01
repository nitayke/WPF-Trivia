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
	
}

void Communicator::startHandleRequests()
{
	while (true)
	{
		SOCKET client_socket = accept(_socket, NULL, NULL); // we have to save the socket somewhere
		if (client_socket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__);

		printf("Client accepted !\n");
		// create new thread for client	and detach from it
		std::thread tr(&handleNewClient, this);
		tr.detach();

		this->m_clients.insert(std::pair<SOCKET, IRequestHandler*>(client_socket, nullptr));
		// we need to replace the null by LoginRequest or something

	}
}
