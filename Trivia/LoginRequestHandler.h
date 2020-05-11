#pragma once
#include "IRequestHandler.h"
#include "HandlersStructs.h"
#include "RequestsStructs.h"

class LoginRequestHandler : public IRequestHandler
{
	bool isRequestRelevant(RequestInfo requestinfo);
	RequestResult handleRequest(RequestInfo requestinfo);
};