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