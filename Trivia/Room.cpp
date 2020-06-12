#include "Room.h"

Room::Room() : m_users()
{
	m_metadata.id = 0;
	m_metadata.isActive = 0;
	m_metadata.maxPlayers = 5;
	m_metadata.name = "";
	m_metadata.timePerQuestion = 10;
}

Room::Room(RoomData roomData)
{
	m_metadata.id = roomData.id;
	m_metadata.isActive = roomData.isActive;
	m_metadata.maxPlayers = roomData.maxPlayers;
	m_metadata.name = roomData.name;
	m_metadata.timePerQuestion = roomData.timePerQuestion;
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
	for (size_t i = 0; i < m_users.size(); i++)
	{
		allUsers.push_back(m_users[i].getUserName());
	}
	return allUsers;
}

RoomData Room::getRoomData()
{
	return m_metadata;
}

