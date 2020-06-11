#pragma once
#include "IDatabase.h"
#include <vector>

class StatisticsManager
{
private:
	IDatabase* m_database;

	std::vector<string> getHighScore();
	std::vector<string> getUserStatistics(string username);
public:
	std::vector<string> getStatistics();
};