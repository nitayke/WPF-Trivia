#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(RequestHandlerFactory& req, RoomManager& roomM, LoggedUser user, Room room) :
	m_handlerFactory(req), m_roomManager(roomM), m_user(user), m_room(room)
{
}

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	return requestInfo.id == LEAVEROOM ||
		requestInfo.id == STARTGAME ||
		requestInfo.id == GETROOMSTATE;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo requestInfo)
{
	switch (requestInfo.id)
	{
	case LEAVEROOM:
		return leaveRoom(requestInfo);
	case STARTGAME:
		return startGame(requestInfo);
	case GETROOMSTATE:
		return getRoomState(requestInfo);
	}
}

RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult RoomMemberRequestHandler::startGame(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo requestInfo)
{
	return RequestResult();
}
