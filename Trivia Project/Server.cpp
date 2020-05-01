#include "Server.h"

void Server::run()
{
	// create new thread for handling message
	std::thread t_connector(&Communicator::startHandleRequests, &m_communicator);
	t_connector.detach();

	std::string command;
	
	while (command != "exit")
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
	}
}
