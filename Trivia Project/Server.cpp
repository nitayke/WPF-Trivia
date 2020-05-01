#include "Server.h"

void Server::run()
{
	WSAInitializer wsa_init;
	// create new thread for handling message
	std::thread t_connector(&Communicator::startHandleRequests, this);
	t_connector.detach();

	std::string command;
	
	while (command != "exit")
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
	}
}
