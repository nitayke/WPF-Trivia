#pragma once
#include <string>

using std::string;

class IDatabase
{
public:
	virtual bool doesUserExist(string username) = 0;
	virtual bool doesPasswordMatch(string username, string password) = 0;
	virtual void addNewUser(string username, string password, string email) = 0;
	virtual float playerAverageAnswerTime(string ans);
	virtual int getNumOfCorrectAnswers(string);
	virtual int getNumOfTotalAnswers(string);
	virtual int getNumOfPlayerGames(string);
};