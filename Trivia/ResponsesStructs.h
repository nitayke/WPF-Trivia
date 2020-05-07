#pragma once
#include <string>

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