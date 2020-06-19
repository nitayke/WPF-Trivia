#pragma once

#include "LoggedUser.h"
#include "Room.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class RoomMemberRequestHandler
{
public:
	RoomMemberRequestHandler(RequestHandlerFactory&, RoomManager&, LoggedUser, Room);
	bool isRequestRelevant(RequestInfo);
	RequestResult handleRequest(RequestInfo);

private:
	RequestResult leaveRoom(RequestInfo);
	RequestResult startGame(RequestInfo);
	RequestResult getRoomState(RequestInfo);

	Room m_room;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handlerFactory;
};

