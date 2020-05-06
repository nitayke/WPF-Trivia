#pragma once
#include <vector>

typedef unsigned char byte;
typedef std::vector<byte> Buffer;

struct RequestInfo;
struct RequestResult;

class IRequestHandler
{
	virtual bool isRequestRelevant(RequestInfo requestinfo) = 0;
	virtual RequestResult handleRequest(RequestInfo requestinfo) = 0;
};