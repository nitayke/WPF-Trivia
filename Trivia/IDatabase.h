#pragma once
#include <string>

using std::string;

class IDatabase
{
public:
	virtual bool doesUserExist(string username) = 0;
	virtual bool doesPasswordMatch(string username, string password) = 0;
	virtual void addNewUser(string username, string password, string email) = 0;
	virtual float playerAverageAnswerTime(string ans) = 0;
	virtual int getNumOfCorrectAnswers(string) = 0;
	virtual int getNumOfTotalAnswers(string) = 0;
	virtual int getNumOfPlayerGames(string) = 0;
};