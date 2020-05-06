#pragma once
#include "HandlersStructs.h"

class IRequestHandler
{
	virtual bool isRequestRelevant(RequestInfo requestinfo) = 0;
	virtual RequestResult handleRequest(RequestInfo requestinfo) = 0;
};