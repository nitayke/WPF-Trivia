#pragma once
#include "LoggedUser.h"
#include "IRequestHandler.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler
{
public:
	MenuRequestHandler(RequestHandlerFactory& req, RoomManager& roomMngr, StatisticsManager& statMngr, LoggedUser user);
	bool isRequestRelevant(RequestInfo);
	RequestResult handleRequest(RequestInfo);

private:
	RequestResult signout(RequestInfo);
	RequestResult getRooms(RequestInfo);
	RequestResult getPlayersInRoom(RequestInfo);
	RequestResult getStatistics(RequestInfo);
	RequestResult joinRoom(RequestInfo);
	RequestResult createRoom(RequestInfo);
	RequestResult closeRoom(RequestInfo);

	int m_id = 0;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	StatisticsManager& m_statisticsManager;
	RequestHandlerFactory& m_handlerFactory;
};

enum IsActive
{
	NOT_ACTIVE,
	ACTIVE
};