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
	LeaveRoomResponse res;
	RequestResult result;
	res.status = 1;
	this->m_room.removeUser(m_user);
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = m_handlerFactory.createMenuRequestHandler(m_user);
	return result;
}

RequestResult RoomMemberRequestHandler::startGame(RequestInfo requestInfo)
{
	StartGameResponse res;
	RequestResult result;
	res.status = 1;
	// start a game?
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = nullptr; // for the next version
	return result;
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo requestInfo)
{
	GetRoomStateResponse res;
	RoomData data = m_room.getRoomData();
	RequestResult result;
	res.answerTimeout = data.timePerQuestion;
	res.hasGameBegun = data.isActive;
	res.players = m_room.getAllUsers();
	res.questionCount = data.questionCount;
	res.status = 1;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = this;
	return result;
}
