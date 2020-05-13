#include "LoginManager.h"

void LoginManager::signup(string username, string password, string email)
{
	if (!m_database->doesUserExist(username))
	{
		m_database->addNewUser(username, password, email);
	}
}

void LoginManager::login(string username, string password)
{
	if (m_database->doesUserExist(username) && m_database->doesPasswordMatch(username, password))
	{
		m_loggedUsers.push_back(LoggedUser(username));
	}
}

void LoginManager::logout(string username)
{
	for (auto i = m_loggedUsers.begin(); i != m_loggedUsers.end(); i++)
	{
		if ((*i).getUserName() == username)
		{
			m_loggedUsers.erase(i);
		}
	}
}
