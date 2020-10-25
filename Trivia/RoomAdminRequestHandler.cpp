#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(RequestHandlerFactory& req, RoomManager& roomM, LoggedUser user, Room& room) :
	m_handlerFactory(req), m_roomManager(roomM), m_user(user), m_room(room)
{
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	return requestInfo.id == CLOSEROOM ||
		requestInfo.id == STARTGAME ||
		requestInfo.id == GETROOMSTATE;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo requestInfo)
{
	switch (requestInfo.id)
	{
	case CLOSEROOM:
		return closeRoom(requestInfo);
	case STARTGAME:
		return startGame(requestInfo);
	case GETROOMSTATE:
		return getRoomState(requestInfo);
	}
}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo requestInfo)
{
	CloseRoomResponse res;
	RequestResult result;
	res.status = 1;
	m_roomManager.deleteRoom(m_room.getRoomData().id);
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = m_handlerFactory.createMenuRequestHandler(m_user);
	return result;
}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo requestInfo)
{
	StartGameResponse res;
	RequestResult result;
	res.status = 1;
	m_room.activateRoom();
	// start game
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = nullptr; // game request handler
	return result;
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo requestInfo)
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
	result.newHandler = m_handlerFactory.createRoomAdminRequestHandler(m_user, m_room);
	return result;
}
