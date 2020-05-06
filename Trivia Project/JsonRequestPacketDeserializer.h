#pragma once
#include "ResponsesStructs.h"
#include "RequestsStructs.h"

class JsonRequestPacketDeserializer
{
public:
	static LoginResponse deserializeLoginRequest(buffer buf);
	static SignupRequest deserializeSignupRequest(buffer buf);
};


