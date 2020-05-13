#pragma once
#include <string>

using std::string;

class LoggedUser
{
private:
	string m_username;
public:
	LoggedUser(string username);
	string getUserName();
};