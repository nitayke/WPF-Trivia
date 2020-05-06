#pragma once
#include "IRequestHandler.h"

class LoginRequestHandler : public IRequestHandler
{
	bool isRequestRelevant(RequestInfo requestinfo);
	RequestResult handleRequest(RequestInfo requestinfo);
};