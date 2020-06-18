#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buf)
{
	int size = buf.size();
	string strMsg = "";
	json msg;
	LoginRequest req;
	for (int i = 5; i < size; i++)
	{
		strMsg += (char)buf[i];
	}
	msg = json::parse(strMsg);
	req.username = msg["username"];
	req.password = msg["password"];

	return req;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buf)
{
	int size = buf.size();
	string strMsg = "";
	json msg;
	SignupRequest req;
	for (int i = 5; i < size; i++)
	{
		strMsg += (char)buf[i];
	}
	msg = json::parse(strMsg);
	req.username = msg["username"];
	req.password = msg["password"];
	req.email = msg["email"];

	return req;
}

GetPlayersInRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(Buffer buf)
{
	int size = buf.size();
	string strMsg = "";
	json msg;
	GetPlayersInRoomRequest req;
	for (int i = 5; i < size; i++)
	{
		strMsg += (char)buf[i];
	}
	msg = json::parse(strMsg);
	req.roomId = msg["roomId"];

	return req;
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(Buffer buf)
{
	int size = buf.size();
	string strMsg = "";
	json msg;
	JoinRoomRequest req;
	for (int i = 5; i < size; i++)
	{
		strMsg += (char)buf[i];
	}
	msg = json::parse(strMsg);
	req.roomId = msg["roomId"];

	return req;
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(Buffer buf)
{
	int size = buf.size();
	string strMsg = "";
	json msg;
	CreateRoomRequest req;
	for (int i = 5; i < size; i++)
	{
		strMsg += (char)buf[i];
	}
	msg = json::parse(strMsg);
	req.roomName = msg["roomName"];
	req.maxUsers = msg["maxUsers"];
	req.questionCount = msg["questionCount"];
	req.answerTimeout = msg["answerTimeout"];

	return req;
}