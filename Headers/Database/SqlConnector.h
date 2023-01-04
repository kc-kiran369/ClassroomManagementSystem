#ifndef SQL_CONNECTOR_H
#define SQL_CONNECTOR_H

#include<iostream>
#include<string>

#include"mysql/include/mysql/jdbc.h"
#include"Windows/MessageBox.h"

namespace cms::Database
{
	struct DatabaseInfo
	{
		std::string server;
		std::string username;
		std::string password;
		std::string database;
		std::string table;
	};

	class SqlConnector
	{
	private:
		static SqlConnector instance;

		sql::Driver* driver = nullptr;
		sql::Connection* con = nullptr;
		sql::Statement* stmt = nullptr;
		sql::ResultSet* res = nullptr;

		DatabaseInfo m_DatabaseInfo;

		SqlConnector();
		SqlConnector(const SqlConnector&) = delete;
	public:
		~SqlConnector();

		static SqlConnector& GetInstance() {
			return instance;
		}

		void Connect();
		DatabaseInfo& GetDatabaseInfo();

		void Insert(std::string& name, std::string& address, int roll);	//Create
		void Retrieve();	//Retrieve
		void Update(int roll, std::string& new_name, std::string& new_address);	//Update
		void Delete(std::string& name, std::string& address, int roll);	//Delete
	};
}

#endif