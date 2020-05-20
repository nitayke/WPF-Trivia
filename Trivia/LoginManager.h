#pragma once
#include <vector>
#include "IDatabase.h"
#include "LoggedUser.h"
#include "ResponsesStructs.h"

class LoginManager
{
private:
	IDatabase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
public:
	LoginManager(IDatabase* db);
	int signup(string username, string password, string email);
	int login(string username, string password);
	void logout(string username);
};