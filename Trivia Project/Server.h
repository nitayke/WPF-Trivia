#pragma once
#include <iostream>
#include "Communicator.h"
#include "WSAInitializer.h"

class Server
{
private:
	Communicator m_communicator;
	
public:
	void run();
};