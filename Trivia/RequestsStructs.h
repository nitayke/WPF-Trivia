#pragma once
#include <string>

struct LoginRequest
{
	std::string username;
	std::string password;
};

struct SignupRequest
{
	std::string username;
	std::string password;
	std::string email;
};

struct GetPlayersInRoomRequest
{
	unsigned int roomId;
};

struct JoinRoomRequest
{
	unsigned int roomId;
};

struct CreateRoomRequest
{
	string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeout;
};

struct GetUserScoreRequest
{
	string username;
};

enum Codes
{
	LOGIN,
	SIGNUP,
	ERRORCODE,
	LOGOUT,
	GETROOMS, // 4
	JOINROOM,
	CREATEROOM,
	GETPLAYERSINROOM,
	GETSTATISTICS, // 8
	CLOSEROOM,
	GETUSERSCORE,
	STARTGAME,
	LEAVEROOM
};