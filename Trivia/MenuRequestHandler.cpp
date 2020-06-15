#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory& req, RoomManager& roomMngr, StatisticsManager& statMngr, LoggedUser user) : 
	m_handlerFactory(req), m_roomManager(roomMngr), m_statisticsManager(statMngr), m_user(user)
{
}

bool MenuRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	return requestInfo.id == LOGOUT ||
		requestInfo.id == GETROOMS ||
		requestInfo.id == JOINROOM ||
		requestInfo.id == CREATEROOM ||
		requestInfo.id == GETPLAYERSINROOM ||
		requestInfo.id == GETSTATISTICS;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo requestInfo)
{
	RequestResult req;
	switch (requestInfo.id)
	{
	case GETROOMS:
		req = this->getRooms(requestInfo);
		break;
	case JOINROOM:
		req = this->joinRoom(requestInfo);
		break;
	case CREATEROOM:
		req = this->createRoom(requestInfo);
		break;
	case GETPLAYERSINROOM:
		req = this->getPlayersInRoom(requestInfo);
		break;
	case GETSTATISTICS:
		req = this->getStatistics(requestInfo);
		break;
	case LOGOUT:
		this->signout(requestInfo);
		break;
	}
	return req;
}

RequestResult MenuRequestHandler::signout(RequestInfo requestInfo)
{
	LogoutResponse res;
	RequestResult result;
	res.status = 1;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = nullptr;
	return result;
}

RequestResult MenuRequestHandler::getRooms(RequestInfo requestInfo)
{
	GetRoomsResponse res;
	RequestResult result;
	res.rooms = m_roomManager.getRooms();
	res.status = 1;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	return result;
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo requestInfo)
{
	GetPlayersInRoomRequest req = JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(requestInfo.buffer);
	GetPlayersInRoomResponse res;
	RequestResult result;
	std::vector<RoomData> rooms = m_roomManager.getRooms();
	for (auto i : rooms)
	{
		if (i.id == req.roomId)
		{
			res.players = m_roomManager.getRoom(i.id).getAllUsers();
			break;
		}
	}
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = nullptr; // TODO: fix that
	return result;
}

RequestResult MenuRequestHandler::getStatistics(RequestInfo requestInfo)
{
	getStatisticsResponse res;
	RequestResult result;
	res.status = 1;
	res.statistics = m_statisticsManager.getStatistics();
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = nullptr; // fix that
	return result;
}

RequestResult MenuRequestHandler::joinRoom(RequestInfo requestInfo)
{
	JoinRoomRequest req = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(requestInfo.buffer);
	RequestResult result;
	JoinRoomResponse res; // need to be fixed
	res.status = 1;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = nullptr; // same
	return result;
}

RequestResult MenuRequestHandler::createRoom(RequestInfo requestInfo)
{
	CreateRoomRequest req = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(requestInfo.buffer);
	RoomData room;
	room.id = m_id;
	room.timePerQuestion = req.answerTimeout;
	room.maxPlayers = req.maxUsers;
	room.name = req.roomName;
	room.isActive = ACTIVE;
	m_roomManager.createRoom(m_user, room);
	CreateRoomResponse CRes;
	CRes.status = 1;
	RequestResult res;
	res.response = JsonResponsePacketSerializer::serializeResponse(CRes);
	res.newHandler = nullptr; //TODO: fix this handler.
	return res;
}