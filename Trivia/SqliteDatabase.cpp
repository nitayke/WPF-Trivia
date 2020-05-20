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

	const char* sqlStatement = "CREATE TABLE USER (USERNAME INTEGER PRIMARY "
		"KEY NOT NULL, PASSWORD "
		"TEXT NOT NULL, EMAIL TEXT NOT NULL); ";

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
	bool exists;
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
	string sqlStatement = "INSERT INTO USER VALUES (" + username + ", "
		+ password + ", " + email + ");";
	sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
}