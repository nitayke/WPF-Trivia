#include "SqliteDatabase.h"

SqliteDatabase::SqliteDatabase()
{
	if (!this->open())
	{
		exit(EXIT_FAILURE);
	}
}

int SqliteDatabase::callback1(void* data, int argc, char** argv, char** azColName)
{
	*(bool*)data = argc > 0;
	return 0;
}

int SqliteDatabase::callback2(void* data, int argc, char** argv, char** azColName)
{
	*(string*)data = argv[0];
	return 0;
}

int SqliteDatabase::callback3(void* data, int argc, char** argv, char** azColName)
{
	*(float*)data = std::atof(argv[0]);
	return 0;
}

int SqliteDatabase::callback4(void* data, int argc, char** argv, char** azColName)
{
	for (size_t i = 0; i < argc; i++)
	{
		(*(std::vector<string>*)data).push_back(string(argv[i]));
	}
	return 0;
}

bool SqliteDatabase::open()
{
	int doesFileExist = _access(dbFileName.c_str(), 0);
	int res = sqlite3_open(dbFileName.c_str(), &db);
	if (res != SQLITE_OK)
	{
		db = nullptr;
		std::cout << "Failed to open DB" << std::endl;
		return false;
	}
	if (doesFileExist == 0)
	{
		return true;
	}

	const char* sqlStatement = "CREATE TABLE USER (USERNAME TEXT PRIMARY "
		"KEY NOT NULL, PASSWORD "
		"TEXT NOT NULL, EMAIL TEXT NOT NULL); ";

	char* errMessage = nullptr;
	res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK || errMessage != nullptr)
		return false;

	sqlStatement = "CREATE TABLE STATISTICS ("
		"ID	INTEGER PRIMARY KEY NOT NULL,"
		" QUESTION_ID	INTEGER NOT NULL,"
		" GAME_ID	INTEGER NOT NULL,"
		" RIGHT	INTEGER NOT NULL,"
		" TIME REAL NOT NULL,"
		" USER TEXT NOT NULL"
		");";

	char* errMessage = nullptr;
	res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK || errMessage != nullptr)
		return false;
	return true;
}

void SqliteDatabase::close()
{
	sqlite3_close(db);
}

bool SqliteDatabase::doesUserExist(string username)
{
	bool exists = false;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT * FROM USER WHERE username=\"" + username + "\";";
	sqlite3_exec(db, sqlStatement.c_str(), callback1, &exists, &errMessage);
	return exists;
}

bool SqliteDatabase::doesPasswordMatch(string username, string password)
{
	std::string second_password;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT password FROM USER WHERE username=\"" + username + "\";";
	sqlite3_exec(db, sqlStatement.c_str(), callback2, &second_password, &errMessage);
	return password == second_password;
}

void SqliteDatabase::addNewUser(string username, string password, string email)
{
	char* errMessage = nullptr;
	string sqlStatement = "INSERT INTO USER VALUES (\"" + username + "\", \""
		+ password + "\", \"" + email + "\");";
	sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
}

float SqliteDatabase::playerAverageAnswerTime(string username)
{
	float avgTime;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT avg(time) FROM STATISTICS WHERE USER=" + username + ";";
	sqlite3_exec(db, sqlStatement.c_str(), callback3, &avgTime, &errMessage);
	return avgTime;
}

int SqliteDatabase::getNumOfCorrectAnswers(string username)
{
	float correctAnswers;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT SUM(right) FROM STATISTICS WHERE USER=" + username + ";";
	sqlite3_exec(db, sqlStatement.c_str(), callback3, &correctAnswers, &errMessage);
	return int(correctAnswers);
}

int SqliteDatabase::getNumOfTotalAnswers(string username)
{
	float totalAnswers;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT COUNT(right) FROM STATISTICS WHERE USER=" + username + ";";
	sqlite3_exec(db, sqlStatement.c_str(), callback3, &totalAnswers, &errMessage);
	return int(totalAnswers);
}

int SqliteDatabase::getNumOfPlayerGames(string username)
{
	float numGames;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT COUNT(DISTINCT game_id) FROM STATISTICS WHERE USER=" + username + ";";
	sqlite3_exec(db, sqlStatement.c_str(), callback3, &numGames, &errMessage);
	return int(numGames);
}

std::vector<string> SqliteDatabase::getQuestions()
{
	std::vector<string> questions;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT QUESTION FROM QUESTIONS;";
	sqlite3_exec(db, sqlStatement.c_str(), callback4, &questions, &errMessage);
	return questions;
}