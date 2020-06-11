#pragma once
#include "ResponsesStructs.h"
#include "RequestsStructs.h"
#include "IRequestHandler.h"
 
class JsonResponsePacketSerializer
{
private:
	static Buffer SerializeRegularResponse(Codes code, unsigned int status);
	static Buffer getLengthBuffer(string jsonMsg);
public:
	static Buffer serializeResponse(ErrorResponse response);
	static Buffer serializeResponse(LoginResponse response);
	static Buffer serializeResponse(SignupResponse response);
	static Buffer serializeResponse(LogoutResponse response);
	static Buffer serializeResponse(GetRoomsResponse response);
	static Buffer serializeResponse(GetPlayersInRoomResponse response);
	static Buffer serializeResponse(JoinRoomResponse response);
	static Buffer serializeResponse(CreateRoomResponse response);
	static Buffer serializeResponse(getStatisticsResponse response);
};