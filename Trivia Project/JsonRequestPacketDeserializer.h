#pragma once

#include <iostream>

class JsonRequestPacketDeserializer
{
public:
	static LoginResponse deserializeLoginRequest(buffer buf);
	static SignupRequest deserializeSignupRequest(buffer buf);

};


