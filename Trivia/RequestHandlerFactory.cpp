#include "RequestHandlerFactory.h"

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	LoginRequestHandler* logR = new LoginRequestHandler(this, &m_loginManager);
	return logR;
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return m_loginManager;
}
