#pragma once
#include <iostream>
#include "Communicator.h"
#include "IDatabase.h"

class Server
{
private:
	Communicator m_communicator;
	IDatabase* m_database;
	RequestHandlerFactory m_handlerFactory;
	
public:
	void run();
};