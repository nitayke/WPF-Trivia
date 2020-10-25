#pragma once
#include "ResponsesStructs.h"
#include "RequestsStructs.h"
#include "IRequestHandler.h"

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(Buffer buf);
	static SignupRequest deserializeSignupRequest(Buffer buf);
	static GetPlayersInRoomRequest deserializeGetPlayersInRoomRequest(Buffer buf);
	static JoinRoomRequest deserializeJoinRoomRequest(Buffer buf);
	static CreateRoomRequest deserializeCreateRoomRequest(Buffer buf);
	static GetUserScoreRequest deserializeGetUserScoreRequest(Buffer buf);
};