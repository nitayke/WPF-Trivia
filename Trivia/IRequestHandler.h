#pragma once
#include <vector>
#include "json.hpp"

using nlohmann::json;
using std::string;

typedef unsigned char byte;
typedef std::vector<byte> Buffer;

struct RequestInfo;
struct RequestResult;

class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo requestinfo) = 0;
	virtual RequestResult handleRequest(RequestInfo requestinfo) = 0;
};