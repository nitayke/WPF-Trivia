#include "LoginManager.h"

int LoginManager::signup(string username, string password, string email)
{
	if (!m_database->doesUserExist(username))
	{
		m_database->addNewUser(username, password, email);
		return SIGNUP_SUCCESS;
	}
	return SIGNUP_USERNAME_EXISTS;
}

int LoginManager::login(string username, string password)
{
	for (auto i = m_loggedUsers.begin(); i != m_loggedUsers.end(); i++)
	{
		if ((*i).getUserName() == username)
		{
			return LOGIN_USER_ALREADY_CONNECTED;
		}
	}
	if (m_database->doesUserExist(username))
	{
		if (m_database->doesPasswordMatch(username, password))
		{
			m_loggedUsers.push_back(LoggedUser(username));
			return LOGIN_SUCCESS;
		}
		else
		{
			return LOGIN_WRONG_PASSWORD;
		}
	}
	else
	{
		return LOGIN_USERNAME_NOT_EXISTS;
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
