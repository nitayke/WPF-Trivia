#pragma once

#include <iostream>
 
class JsonResponsePacketSerializer
{
public:
	static buffer SerializeResponse(ErrorResponse response);
	static buffer SerializeResponse(LoginResponse response);
	static buffer SerializeResponse(SignupResponse response);

};
