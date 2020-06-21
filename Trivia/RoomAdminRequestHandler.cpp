#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(RequestHandlerFactory& req, RoomManager& roomM, LoggedUser user, Room room) :
	m_handlerFactory(req), m_roomManager(roomM), m_user(user), m_room(room)
{
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	return requestInfo.id == CLOSEROOM ||
		requestInfo.id == STARTGAME ||
		requestInfo.id == GETROOMSTATE;
}
