#pragma once
#include "IDatabase.h"
#include <vector>
#include <map>

class StatisticsManager
{
private:
	IDatabase* m_database;

	std::vector<string> getHighScore();
public:
	StatisticsManager(IDatabase* db);
	std::vector<string> getStatistics();
	std::vector<string> getUserStatistics(string username);
};