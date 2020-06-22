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
		requestInfo.id == GETSTATISTICS ||
		requestInfo.id == CLOSEROOM ||
		requestInfo.id == GETUSERSCORE;
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
		req = this->signout(requestInfo);
		break;
	case CLOSEROOM:
		req = this->closeRoom(requestInfo);
		break;
	case GETUSERSCORE:
		req = this->getUserScore(requestInfo);
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
	result.newHandler = m_handlerFactory.createLoginRequestHandler(m_user.getUserName());
	return result;
}

RequestResult MenuRequestHandler::getRooms(RequestInfo requestInfo)
{
	GetRoomsResponse res;
	RequestResult result;
	res.rooms = m_roomManager.getRooms();
	res.status = 1;
	result.newHandler = this;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	return result;
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo requestInfo)
{
	GetPlayersInRoomRequest req = JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(requestInfo.buffer);
	GetPlayersInRoomResponse res;
	RequestResult result;
	std::vector<RoomData> rooms = m_roomManager.getRooms();
	if (req.roomId == -1) // if there are no players in the room
	{
		result.response = JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse());
		result.newHandler = this;
		return result;
	}
	for (auto i : rooms)
	{
		if (i.id == req.roomId)
		{
			res.players = m_roomManager.getRoom(i.id).getAllUsers();
			break;
		}
	}
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = this;
	return result;
}

RequestResult MenuRequestHandler::getStatistics(RequestInfo requestInfo)
{
	getStatisticsResponse res;
	RequestResult result;
	res.status = 1;
	res.statistics = m_statisticsManager.getStatistics();
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = this;
	return result;
}

RequestResult MenuRequestHandler::joinRoom(RequestInfo requestInfo)
{
	JoinRoomRequest req = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(requestInfo.buffer);
	RequestResult result;
	JoinRoomResponse res;
	m_roomManager.addUserToRoom(req.roomId, m_user);
	res.status = 1;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = m_handlerFactory.createRoomMemberRequestHandler(m_user, m_roomManager.getRoom(req.roomId)); 
	return result;
}

RequestResult MenuRequestHandler::createRoom(RequestInfo requestInfo)
{
	CreateRoomRequest req = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(requestInfo.buffer);
	RoomData room;
	room.id = m_id;
	room.timePerQuestion = req.answerTimeout;
	room.questionCount = req.questionCount;
	room.maxPlayers = req.maxUsers;
	room.name = req.roomName;
	room.isActive = NOT_ACTIVE;
	m_roomManager.createRoom(m_user, room);
	CreateRoomResponse CRes;
	CRes.roomId = m_id;
	CRes.status = 1;
	RequestResult res;
	res.response = JsonResponsePacketSerializer::serializeResponse(CRes);
	res.newHandler = m_handlerFactory.createRoomAdminRequestHandler(m_user, m_roomManager.getRoom(room.id));
	m_id++;
	return res;
}

RequestResult MenuRequestHandler::closeRoom(RequestInfo requestInfo)
{
	LogoutResponse res;
	RequestResult result;
	JoinRoomRequest req = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(requestInfo.buffer);
	m_roomManager.deleteRoom(req.roomId);
	res.status = 1;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = this;
	return result;
}

RequestResult MenuRequestHandler::getUserScore(RequestInfo requestInfo)
{
	getStatisticsResponse res;
	RequestResult result;
	res.status = 1;
	res.statistics = m_statisticsManager.getUserStatistics("nitay");
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	result.newHandler = this;
	return result;
}
