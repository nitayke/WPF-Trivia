#pragma once
#include "ResponsesStructs.h"
 
class JsonResponsePacketSerializer
{
public:
	static std::string SerializeResponse(ErrorResponse response);
	static std::string SerializeResponse(LoginResponse response);
	static std::string SerializeResponse(SignupResponse response);

};
