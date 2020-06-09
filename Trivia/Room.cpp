#include "Room.h"

Room::Room(RoomData roomData)
{
	m_metadata = roomData;
}

void Room::addUser(LoggedUser user)
{
	m_users.push_back(user);
}

void Room::removeUser(LoggedUser user)
{
	int pos = 0;
	auto itr = m_users.begin();
	while (itr != m_users.end())
	{
		if (itr->getUserName() == user.getUserName())
		{
			break;
		}
		else
		{
			itr++;
			pos++;
		}
	}
	m_users.erase(m_users.begin() + pos);
}

std::vector<string> Room::getAllUsers()
{
	std::vector<string> allUsers;
	for (int i = 0; i < m_users.size(); i++)
	{
		allUsers.push_back(m_users[i].getUserName());
	}
	return allUsers;
}

RoomData Room::getRoomData()
{
	return m_metadata;
}

