#include "JsonRequestPacketDeserializer.h"


LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buf)
{
	int size = buf.size(), pos;
	string strMsg = "", temp;
	json msg;
	LoginRequest req;
	for (int i = 5; i < size; i++)
	{
		strMsg += (char)buf[i];
	}
	msg = json::parse(strMsg);
	req.username = msg["username"];
	req.password = msg["password"];

	/*temp = strMsg.substr(strMsg.find(":") + 3, strMsg.find(",") - (strMsg.find(":") + 3));
	pos = strMsg.find(",");
	temp = strMsg.substr(strMsg.find(":", pos) + 3, strMsg.find(",", pos) - (strMsg.find(":", pos) + 3));*/
	
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
