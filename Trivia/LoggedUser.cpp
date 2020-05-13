#include "LoggedUser.h"

LoggedUser::LoggedUser(string username)
{
	m_username = username;
}

string LoggedUser::getUserName()
{
	return m_username;
}