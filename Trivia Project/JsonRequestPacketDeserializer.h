#pragma once
#include "ResponsesStructs.h"
#include "RequestsStructs.h"
#include "IRequestHandler.h"

class JsonRequestPacketDeserializer
{
public:
	static LoginResponse deserializeLoginRequest(Buffer buf);
	static SignupRequest deserializeSignupRequest(Buffer buf);
};


