#pragma once
#include "ResponsesStructs.h"
#include "RequestsStructs.h"

class JsonRequestPacketDeserializer
{
public:
	static LoginResponse deserializeLoginRequest(std::string buf);
	static SignupRequest deserializeSignupRequest(std::string buf);
};


