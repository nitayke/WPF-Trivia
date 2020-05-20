#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(LoginManager logMngr, IDatabase* db) : 
	m_loginManager(logMngr)
{
	this->m_database = db;
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	return new LoginRequestHandler(this, &m_loginManager);
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return m_loginManager;
}