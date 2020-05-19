#pragma once
#include <vector>
#include "IDatabase.h"
#include "LoggedUser.h"

class LoginManager
{
private:
	IDatabase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
public:
	void signup(string username, string password, string email);
	void login(string username, string password);
	void logout(string username);
};