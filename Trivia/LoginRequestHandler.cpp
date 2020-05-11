#include "LoginRequestHandler.h"
#include "JsonResponsePacketSerializer.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo requestinfo)
{
	return requestinfo.id == LOGIN || requestinfo.id == SIGNUP;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo requestinfo)
{
	RequestResult req;
	LoginResponse res;
	res.status = LOGIN_SUCCESS;
	req.response = JsonResponsePacketSerializer::SerializeResponse(res);
	req.newHandler = nullptr;
	return req;
}
