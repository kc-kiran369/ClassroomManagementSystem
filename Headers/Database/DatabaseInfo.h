#ifndef DATABASE_INFO_H
#define DATABASE_INFO_H

namespace cms::Database
{
	struct DatabaseInfo
	{
		char server[15] = "127.0.0.1";
		char username[15] = "root";
		char password[15] = "";
		char database[15] = "mydatabase";
		char table[15] = "student";
	};
}

#endif