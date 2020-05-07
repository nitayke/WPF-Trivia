#pragma once
#include "ResponsesStructs.h"
#include "IRequestHandler.h"
 
class JsonResponsePacketSerializer
{
private:
	static Buffer getLengthBuffer(string jsonMsg);
public:
	static Buffer SerializeResponse(ErrorResponse response);
	static Buffer SerializeResponse(LoginResponse response);
	static Buffer SerializeResponse(SignupResponse response);
};