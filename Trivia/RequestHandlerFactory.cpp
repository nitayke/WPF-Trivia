#include "RequestHandlerFactory.h"

LoginRequestHandler& RequestHandlerFactory::createLoginRequestHandler()
{
	LoginRequestHandler* log = new LoginRequestHandler((*this), getLoginManager());
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return m_loginManager;
}
