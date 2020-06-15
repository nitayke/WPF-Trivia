#include "Server.h"

Server::Server() : m_database(new SqliteDatabase()),
	m_handlerFactory(LoginManager(m_database), m_database, RoomManager(), StatisticsManager()),
	m_communicator(&m_handlerFactory)
{
}

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