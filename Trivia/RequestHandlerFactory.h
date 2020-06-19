#pragma once
#include "IDatabase.h"
#include "LoginManager.h"
#include "LoginRequestHandler.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "RoomAdminRequestHandler.h"

#include <vector>

class LoginRequestHandler;
class MenuRequestHandler;
class RoomMemberRequestHandler;
class RoomAdminRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(LoginManager, IDatabase*, RoomManager, StatisticsManager);
	LoginRequestHandler* createLoginRequestHandler();
	LoginRequestHandler* createLoginRequestHandler(string loggedOutUser);
	LoginManager& getLoginManager();
	MenuRequestHandler* createMenuRequestHandler(LoggedUser);
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();

private:
	LoginManager m_loginManager;
	IDatabase* m_database;
	RoomManager m_roomManager;
	StatisticsManager m_StatisticsManager;
};
