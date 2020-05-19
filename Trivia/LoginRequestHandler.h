#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "HandlersStructs.h"
#include "JsonResponsePacketSerializer.h"

class LoginRequestHandler : public IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo requestinfo);
	RequestResult handleRequest(RequestInfo requestinfo);

private:
	RequestHandlerFactory m_handlerFactory;

	RequestResult login(RequestInfo requestinfo);
	RequestResult signup(RequestInfo requestinfo);
};