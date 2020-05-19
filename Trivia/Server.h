#pragma once
#include <iostream>
#include "Communicator.h"
#include "IDatabase.h"

class Server
{
private:
	Communicator m_communicator;
	IDatabase* m_database;
	
public:
	void run();
};