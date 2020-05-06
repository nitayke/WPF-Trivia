#pragma once
#include <time.h>
#include <vector>
#include "IRequestHandler.h"

struct RequestResult
{
	buffer response;
	IRequestHandler* newHandler;
};

struct RequestInfo
{
	RequestId id;
	time_t receivalTime;
	std::vector<unsigned int> buffer;
};