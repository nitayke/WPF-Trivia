#pragma once
#include <map>
#include "Room.h"

class RoomManager
{
private:
	std::map<int, Room> m_rooms;
public:
	void createRoom(LoggedUser user, RoomData roomData);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	std::vector<RoomData> getRooms();
	Room& getRoom(int ID);
	void addUserToRoom(int roomId, LoggedUser user);
	bool doesRoomExist(int ID);
};