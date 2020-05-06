#include "LoginRequestHandler.h"
#include "HandlersStructs.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo requestinfo)
{
	return false;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo requestinfo)
{
	return RequestResult();
}
