#include "Communicator.h"

Communicator::Communicator(RequestHandlerFactory* reqFactory)
{
	_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
	m_handlerFactory = reqFactory;
}

Communicator::~Communicator()
{
	try
	{
		::closesocket(_socket);
	}
	catch (...) {}
}

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
	IRequestHandler* handler = m_clients[client_socket];
	RequestInfo info;
	RequestResult result;
	Buffer tmp;
	char buffer[1024] = { 0 };
	while (true)
	{
		int res = recv(client_socket, buffer, 1024, 0);
		if (buffer[0] == 0 && buffer[4] == 0)
		{
			return;
		}
		if (res == INVALID_SOCKET)
		{
			throw std::exception("Error while recieving from socket");
		}
		time(&info.receivalTime);
		for (size_t i = 0; i < 1024; i++)
		{
			tmp.push_back((byte)buffer[i]);
		}
		info.buffer = tmp;
		info.id = tmp[0];
		if (!handler->isRequestRelevant(info))
		{
			return;
		}
		result = handler->handleRequest(info);
		delete handler;
		std::string strBuff(result.response.begin(), result.response.end());
		std::cout << "Sending: " << strBuff << std::endl;
		if (send(client_socket, strBuff.c_str(), 1024, 0) == INVALID_SOCKET)
			throw std::exception("Error while sending message to client");
		handler = result.newHandler;
		for (int i = 0; i < 1024; i++) // reset the buffer
			buffer[i] = '\0';
		tmp.clear();
	}
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
		m_clients.insert(std::pair<SOCKET, IRequestHandler*>(client_socket, 
			m_handlerFactory->createLoginRequestHandler()));
		std::thread tr(&Communicator::handleNewClient, this, client_socket);
		tr.detach();
	}
}
