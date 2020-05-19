#include "JsonResponsePacketSerializer.h"

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

Buffer JsonResponsePacketSerializer::SerializeResponse(ErrorResponse response)
{
	json msg;
	msg["message"] = response.message;
	string strMsg = msg.dump();
	int msgLen = strMsg.length();
	Buffer responseBuffer;
	responseBuffer.push_back(LOGIN);
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

Buffer JsonResponsePacketSerializer::SerializeResponse(LoginResponse response)
{
	json msg;
	msg["status"] = response.status;
	string strMsg = msg.dump();
	int msgLen = strMsg.length();
	Buffer responseBuffer;
	responseBuffer.push_back(LOGIN);
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

Buffer JsonResponsePacketSerializer::SerializeResponse(SignupResponse response)
{
	LoginResponse alternativeResponse;
	alternativeResponse.status = response.status;
	return SerializeResponse(alternativeResponse);
}
