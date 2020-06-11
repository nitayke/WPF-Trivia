#pragma once
#include "IDatabase.h"
#include "sqlite3.h"
#include <iostream>
#include <io.h>

class SqliteDatabase : public IDatabase
{
private:
	sqlite3* db;
	string dbFileName = "db.sqlite";

	static int callback1(void* data, int argc, char** argv, char** azColName);
	static int callback2(void* data, int argc, char** argv, char** azColName);
	static int callback3(void* data, int argc, char** argv, char** azColName);
	static int callback4(void* data, int argc, char** argv, char** azColName);
public:
	SqliteDatabase();
	bool open();
	void close();
	bool doesUserExist(string username) override;
	bool doesPasswordMatch(string username, string password) override;
	void addNewUser(string username, string password, string email) override;
	float playerAverageAnswerTime(string ans)override;
	int getNumOfCorrectAnswers(string) override;
	int getNumOfTotalAnswers(string) override;
	int getNumOfPlayerGames(string) override;
	std::vector<string> getQuestions() override; // should get int
};