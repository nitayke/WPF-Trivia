#include "Server.h"

int main()
{
	try
	{
		WSAInitializer wsa_init;
		Server m_server;
		m_server.run();
	}
	catch (const std::exception & e)
	{
		std::cout << "Exception was thrown in function: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception in main !" << std::endl;
	}

	return 0;
}