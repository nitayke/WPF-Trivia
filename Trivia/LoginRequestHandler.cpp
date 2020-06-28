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
		req = login(requestinfo);
	}
	else if (requestinfo.id == SIGNUP)
	{
		req = signup(requestinfo);
	}
	return req;
}

RequestResult LoginRequestHandler::login(RequestInfo requestinfo)
{
	LoginResponse res;
	LoginRequest req = JsonRequestPacketDeserializer::deserializeLoginRequest(requestinfo.buffer);
	RequestResult result;
	res.status = m_loginManager->login(req.username, req.password);
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	if (res.status == LOGIN_SUCCESS)
		result.newHandler = m_handlerFactory->createMenuRequestHandler(LoggedUser(req.username));
	else
		result.newHandler = m_handlerFactory->createLoginRequestHandler();
	return result;
}

RequestResult LoginRequestHandler::signup(RequestInfo requestinfo)
{
	SignupResponse res;
	SignupRequest req = JsonRequestPacketDeserializer::deserializeSignupRequest(requestinfo.buffer);
	RequestResult result;
	res.status = m_loginManager->signup(req.username, req.password, req.email);
	result.response = JsonResponsePacketSerializer::serializeResponse(res);
	if (res.status == SIGNUP_SUCCESS)
		result.newHandler = m_handlerFactory->createMenuRequestHandler(LoggedUser(req.username));
	else
		result.newHandler = m_handlerFactory->createLoginRequestHandler();
	return result;
}