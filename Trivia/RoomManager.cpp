#include "RoomManager.h"

void RoomManager::createRoom(LoggedUser user, RoomData roomData)
{
	Room* room = new Room(roomData, user);
	m_rooms.insert(std::pair<int, Room>(roomData.id, *room));
}

void RoomManager::deleteRoom(int ID)
{
	m_rooms.erase(ID);
}

unsigned int RoomManager::getRoomState(int ID)
{
	auto itr = m_rooms.find(ID);
	return itr->second.getRoomData().isActive;
}

std::vector<RoomData> RoomManager::getRooms()
{
	std::vector<RoomData> roomsData;
	for (auto itr = m_rooms.begin(); itr != m_rooms.end(); itr++)
	{
		roomsData.push_back(itr->second.getRoomData());
	}
	return roomsData;
}

Room& RoomManager::getRoom(int ID)
{
	return this->m_rooms[ID];
}

void RoomManager::addUserToRoom(int roomId, LoggedUser user)
{
	m_rooms[roomId].addUser(user);
}

bool RoomManager::doesRoomExist(int ID)
{
	for (auto room : m_rooms)
	{
		if (room.first == ID)
			return true;
	}
	return false;
}
