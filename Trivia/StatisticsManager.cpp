#include "StatisticsManager.h"

std::vector<string> StatisticsManager::getHighScore()
{
	//score = ((right/all)/time) * 1000
	// username, score
	int maxScore = 0;
	std::vector<string> result;
	for (string username : m_database->getPlayers())
	{
		int correct = m_database->getNumOfCorrectAnswers(username);
		int total = m_database->getNumOfTotalAnswers(username);
		float time = m_database->playerAverageAnswerTime(username);
		if (((correct / total) / time) * 1000 > maxScore)
		{
			result.clear();
			maxScore = ((correct / total) / time) * 1000;
			result.push_back(username);
			result.push_back(std::to_string(maxScore));
		}
	}
	return result;
}

std::vector<string> StatisticsManager::getUserStatistics(string username)
{
	// avgtime, correct, total, gamesnumber
	std::vector<string> result;
	result.push_back(std::to_string(m_database->playerAverageAnswerTime(username)));
	result.push_back(std::to_string(m_database->getNumOfCorrectAnswers(username)));
	result.push_back(std::to_string(m_database->getNumOfTotalAnswers(username)));
	result.push_back(std::to_string(m_database->getNumOfPlayerGames(username)));
	return result;
}

StatisticsManager::StatisticsManager(IDatabase* db)
{
	m_database = db;
}

std::vector<string> StatisticsManager::getStatistics() // records
{
	// user1, score1, user2, score2, user3, score3... score5
	int score = 0;
	std::map<int, string> scores;
	std::vector<string> tmp;
	std::vector<string> result;
	int negative = -1;
	for (string username : m_database->getPlayers())
	{
		int correct = m_database->getNumOfCorrectAnswers(username);
		int total = m_database->getNumOfTotalAnswers(username);
		float time = m_database->playerAverageAnswerTime(username);
		if (total == 0)
			score = negative;
		else
			score = ((correct / total) / time) * 1000;
		scores[score] = username;
		negative -= 1;
	}
	for (auto i = scores.begin(); i != scores.end(); i++)
	{
		tmp.push_back(std::to_string(i->first));
		tmp.push_back(i->second);
	}
	int lim;
	if (tmp.size() < 11)
		lim = tmp.size();
	else
		lim = 11;
	for (size_t i = 1; i <= lim; i++)
	{
		result.push_back(tmp[tmp.size() - i]);
	}
	return result;
}