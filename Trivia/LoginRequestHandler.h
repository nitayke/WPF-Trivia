#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "HandlersStructs.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"

class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler(RequestHandlerFactory* req, LoginManager* logM);
	bool isRequestRelevant(RequestInfo requestinfo);
	RequestResult handleRequest(RequestInfo requestinfo);

private:
	RequestHandlerFactory* m_handlerFactory;
	LoginManager* m_loginManager;

	RequestResult login(RequestInfo requestinfo);
	RequestResult signup(RequestInfo requestinfo);
};