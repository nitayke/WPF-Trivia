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
	static Buffer SerializeResponse(ErrorResponse response);
	static Buffer SerializeResponse(LoginResponse response);
	static Buffer SerializeResponse(SignupResponse response);
	static Buffer serializeResponse(LogoutResponse response);
	static Buffer serializeResponse(GetRoomsResponse response);
	static Buffer serializerResponse(GetPlayersInRoomResponse response);
	static Buffer serializeResponse(JoinRoomResponse response);
	static Buffer serializeResponse(CreateRoomResponse response);
	static Buffer serializeResponse(getStatisticsResponse response);
};