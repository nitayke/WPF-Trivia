#include "JsonRequestPacketDeserializer.h"
#include <bitset>

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(Buffer buf)
{
	int size = buf.size();
	string strMsg = "";
	json mag;
	for (int i = 0; i < size - 5; i++)
	{
		strMsg += (char)buf.back();
	}
	
	return LoginRequest();
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(Buffer buf)
{
	return SignupRequest();
}
