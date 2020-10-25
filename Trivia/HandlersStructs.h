#pragma once
#include <time.h>
#include <vector>
#include "IRequestHandler.h"

struct RequestResult
{
	Buffer response;
	IRequestHandler* newHandler;
};

struct RequestInfo
{
	byte id;
	time_t receivalTime;
	Buffer buffer;
};