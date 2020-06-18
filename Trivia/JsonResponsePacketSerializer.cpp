#include "JsonResponsePacketSerializer.h"

Buffer JsonResponsePacketSerializer::SerializeRegularResponse(Codes code, unsigned int status)
{
	json msg;
	msg["status"] = status;
	string strMsg = msg.dump();
	int msgLen = strMsg.length();
	Buffer responseBuffer;
	responseBuffer.push_back(code);
	for (auto i : getLengthBuffer(strMsg))
	{
		responseBuffer.push_back(i);
	}
	for (auto i : strMsg)
	{
		responseBuffer.push_back((byte)i);
	}
	return responseBuffer;
}

Buffer JsonResponsePacketSerializer::getLengthBuffer(string jsonMsg)
{
	Buffer responseBuffer;
	int msgLen = jsonMsg.length();
	responseBuffer.push_back(msgLen / (256 * 256 * 256));
	responseBuffer.push_back((msgLen / (256 * 256)) % 256);
	responseBuffer.push_back((msgLen / 256) % 256);
	responseBuffer.push_back(msgLen % 256);
	return responseBuffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
	json msg;
	msg["message"] = response.message;
	string strMsg = msg.dump();
	int msgLen = strMsg.length();
	Buffer responseBuffer;
	responseBuffer.push_back(ERRORCODE);
	for (auto i : getLengthBuffer(strMsg))
	{
		responseBuffer.push_back(i);
	}
	for (auto i : strMsg)
	{
		responseBuffer.push_back((byte)i);
	}
	return responseBuffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
	return SerializeRegularResponse(LOGIN, response.status);
}

Buffer JsonResponsePacketSerializer::serializeResponse(SignupResponse response)
{
	return SerializeRegularResponse(SIGNUP, response.status);
}

Buffer JsonResponsePacketSerializer::serializeResponse(LogoutResponse response)
{
	return SerializeRegularResponse(LOGOUT, response.status);
}

Buffer JsonResponsePacketSerializer::serializeResponse(GetRoomsResponse response)
{
	json msg;
	string room;
	for (auto i : response.rooms)
	{
		room += i.name + ", ";
	}
	room = room.substr(0, room.length() - 2);
	msg["Rooms"] = room;
	string strMsg = msg.dump();
	int msgLen = strMsg.length();
	Buffer responseBuffer;
	responseBuffer.push_back(GETROOMS);
	for (auto i : getLengthBuffer(strMsg))
	{
		responseBuffer.push_back(i);
	}
	for (auto i : strMsg)
	{
		responseBuffer.push_back((byte)i);
	}
	return responseBuffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse response)
{
	json msg;
	string playersInRoom;
	Buffer responseBuffer;
	for (auto i : response.players)
	{
		playersInRoom += i + ", ";
	}
	playersInRoom = playersInRoom.substr(0, playersInRoom.length() - 2);
	msg["PlayersInRoom"] = playersInRoom;
	string strMsg = msg.dump();
	int msgLen = strMsg.length();
	responseBuffer.push_back(GETROOMS);
	for (auto i : getLengthBuffer(strMsg))
	{
		responseBuffer.push_back(i);
	}
	for (auto i : strMsg)
	{
		responseBuffer.push_back((byte)i);
	}
	return responseBuffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse response)
{
	return SerializeRegularResponse(JOINROOM, response.status);
}

Buffer JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse response)
{
	json msg;
	msg["status"] = response.status;
	msg["roomId"] = response.roomId;
	Buffer responseBuffer;
	string strMsg = msg.dump();
	for (auto i : getLengthBuffer(strMsg))
	{
		responseBuffer.push_back(i);
	}
	for (auto i : strMsg)
	{
		responseBuffer.push_back((byte)i);
	}
	return responseBuffer;
}

Buffer JsonResponsePacketSerializer::serializeResponse(getStatisticsResponse response)
{
	json msg;
	string statistics;
	for (auto i : response.statistics)
	{
		statistics += i + ", ";
	}
	statistics = statistics.substr(0, statistics.length() - 2);
	msg["UserStatistics"] = statistics;
	string strMsg = msg.dump();
	int msgLen = strMsg.length();
	Buffer responseBuffer;
	responseBuffer.push_back(GETROOMS);
	for (auto i : getLengthBuffer(strMsg))
	{
		responseBuffer.push_back(i);
	}
	for (auto i : strMsg)
	{
		responseBuffer.push_back((byte)i);
	}
	return responseBuffer;
}
