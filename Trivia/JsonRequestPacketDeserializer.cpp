#include "JsonRequestPacketDeserializer.h"


LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buf)
{
	int size = buf.size();
	string strMsg = "";
	json msg;
	for (int i = 5; i < size; i++)
	{
		strMsg += (char)buf[i];
	}

	
	return LoginRequest();
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buf)
{
	return SignupRequest();
}
