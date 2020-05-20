#pragma once
#include <iostream>
#include "Communicator.h"
#include "RequestHandlerFactory.h"
#include "SqliteDatabase.h"

class Server
{
private:
	Communicator m_communicator;
	IDatabase* m_database;
	RequestHandlerFactory m_handlerFactory;
	
public:
	Server();
	void run();
};