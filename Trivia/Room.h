#pragma once
#include "RoomData.h"
#include "LoggedUser.h"
#include <vector>

class Room
{
public:
	Room();
	Room(RoomData roomData, LoggedUser user);
	void addUser(LoggedUser user);
	void removeUser(LoggedUser user);
	std::vector<string> getAllUsers();
	RoomData getRoomData();
	void activateRoom();

private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
};

