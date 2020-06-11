#pragma once
#include "IDatabase.h"
#include <vector>
#include <map>

class StatisticsManager
{
private:
	IDatabase* m_database;

	std::vector<string> getHighScore();
	std::vector<string> getUserStatistics(string username);
public:
	std::vector<string> getStatistics();
};