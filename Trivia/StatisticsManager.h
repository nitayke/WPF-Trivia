#pragma once
#include "IDatabase.h"

class StatisticsManager
{
private:
	IDatabase* m_database;
public:
	void getStatistics();
};