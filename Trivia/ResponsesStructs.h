#pragma once
#include <string>
#include "RoomData.h"
#include <vector>

using std::string;

struct LoginResponse
{
	unsigned int status;
};

struct SignupResponse
{
	unsigned int status;
};

struct ErrorResponse
{
	std::string message;
};

struct LogoutResponse
{
	unsigned int status;
};

struct GetRoomsResponse
{
	unsigned int status;
	std::vector<RoomData> rooms;
};

struct GetPlayersInRoomResponse
{
	std::vector<string> players;
};

struct getStatisticsResponse
{
	unsigned int status;
	std::vector<string> statistics;
};

struct JoinRoomResponse
{
	unsigned int status;
};

struct CreateRoomResponse
{
	int roomId;
	unsigned int status;
};

struct CloseRoomResponse
{
	unsigned int status;
};

struct StartGameResponse
{
	unsigned int status;
};

struct GetRoomStateResponse
{
	unsigned int status;
	bool hasGameBegun;
	std::vector<string> players;
	unsigned int questionCount;
	unsigned int answerTimeout;
};

struct LeaveRoomResponse
{
	unsigned int status;
};

enum LoginCode
{
	LOGIN_SUCCESS,
	LOGIN_USERNAME_NOT_EXISTS,
	LOGIN_WRONG_PASSWORD,
	LOGIN_USER_ALREADY_CONNECTED
};

enum SignupCode
{
	SIGNUP_SUCCESS,
	SIGNUP_USERNAME_EXISTS
};