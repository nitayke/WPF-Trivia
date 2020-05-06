#pragma once
#include "ResponsesStructs.h"
#include "IRequestHandler.h"
 
class JsonResponsePacketSerializer
{
public:
	static Buffer SerializeResponse(ErrorResponse response);
	static Buffer SerializeResponse(LoginResponse response);
	static Buffer SerializeResponse(SignupResponse response);
};