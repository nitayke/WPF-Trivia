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
