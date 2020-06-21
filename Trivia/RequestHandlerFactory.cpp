#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(LoginManager logMngr, IDatabase* db, RoomManager roomMngr, StatisticsManager statMngr) : 
	m_loginManager(logMngr), m_roomManager(roomMngr), m_StatisticsManager(statMngr)
{
	m_database = db;
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	return new LoginRequestHandler(this, &m_loginManager);
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler(string loggedOutUser)
{
	m_loginManager.logout(loggedOutUser);
	return new LoginRequestHandler(this, &m_loginManager);
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return m_loginManager;
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(LoggedUser user)
{
	return new MenuRequestHandler(*this, m_roomManager, m_StatisticsManager, user);
}

StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
	return m_StatisticsManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
	return m_roomManager;
}

RoomAdminRequestHandler* RequestHandlerFactory::createRoomAdminRequestHandler(LoggedUser user, Room room)
{
	return new RoomAdminRequestHandler(*this, m_roomManager, user, room);
}

RoomMemberRequestHandler* RequestHandlerFactory::createRoomMemberRequestHandler(LoggedUser user, Room room)
{
	return new RoomMemberRequestHandler(*this, m_roomManager, user, room);
}
