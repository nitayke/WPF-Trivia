#include "LoginRequestHandler.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo requestinfo)
{
	return requestinfo.id == LOGIN || requestinfo.id == SIGNUP;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo requestinfo)
{
	return RequestResult();
}
