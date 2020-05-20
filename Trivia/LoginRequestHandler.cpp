#include "LoginRequestHandler.h"

LoginRequestHandler::LoginRequestHandler(RequestHandlerFactory* req, LoginManager* logM)
{
	m_handlerFactory = req;
	m_loginManager = logM;
}

bool LoginRequestHandler::isRequestRelevant(RequestInfo requestinfo)
{
	return requestinfo.id == LOGIN || requestinfo.id == SIGNUP;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo requestinfo)
{
	RequestResult req;
	if (requestinfo.id == LOGIN)
	{
		req = this->login(requestinfo);
	}
	else if (requestinfo.id == SIGNUP)
	{
		req = this->signup(requestinfo);
	}
	return req;
}

RequestResult LoginRequestHandler::login(RequestInfo requestinfo)
{
	LoginResponse res;
	LoginRequest req = JsonRequestPacketDeserializer::deserializeLoginRequest(requestinfo.buffer);
	res.status = m_loginManager->login(req.username, req.password);
	RequestResult result;
	result.response = JsonResponsePacketSerializer::SerializeResponse(res);
	result.newHandler = nullptr;
	return result;
}

RequestResult LoginRequestHandler::signup(RequestInfo requestinfo)
{
	SignupResponse res;
	SignupRequest req = JsonRequestPacketDeserializer::deserializeSignupRequest(requestinfo.buffer);
	res.status = m_loginManager->signup(req.username, req.password, req.email);
	RequestResult result;
	result.response = JsonResponsePacketSerializer::SerializeResponse(res);
	result.newHandler = m_handlerFactory->createLoginRequestHandler();
	return result;
}