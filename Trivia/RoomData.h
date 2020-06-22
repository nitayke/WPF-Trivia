#pragma once
#include <iostream>

struct RoomData 
{
	unsigned int id;
	std::string name;
	int maxPlayers;
	unsigned int timePerQuestion;
	unsigned int isActive;
	unsigned int questionCount;
};
