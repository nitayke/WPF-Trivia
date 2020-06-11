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
	return RequestResult();
}

RequestResult MenuRequestHandler::getRooms(RequestInfo requestInfo)
{
	GetRoomsResponse res;
	res.rooms = m_roomManager.getRooms();
	RequestResult result;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	return result;
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::getStatistics(RequestInfo requestInfo)
{
	getStatisticsResponse res;
	res.statistics = m_statisticsManager.getStatistics();
	RequestResult result;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	return result;
}

RequestResult MenuRequestHandler::joinRoom(RequestInfo requestInfo)
{
	JoinRoomRequest req = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(requestInfo.buffer);
	JoinRoomResponse res; // need to be fixed
	RequestResult result;
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	return result;
}

RequestResult MenuRequestHandler::createRoom(RequestInfo requestInfo)
{
	CreateRoomRequest req = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(requestInfo.buffer);
	m_roomManager.createRoom(req.something);
}