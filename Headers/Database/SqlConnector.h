#ifndef SQL_CONNECTOR_H
#define SQL_CONNECTOR_H

#include<iostream>
#include<string>

#include"mysql/include/mysql/jdbc.h"
#include"DatabaseInfo.h"
#include"Windows/MessageBox.h"
#include"Data/StudentRegistry.h"

namespace cms::Database
{
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

		static SqlConnector& GetInstance() { return instance; }

		void ChangeServer(const char* server);
		void ChangeUser(const char* user);
		void ChangePassword(const char* password);
		void ChangeDatabase(const char* database);
		void ChangeTable(const char* table);

		void Connect();
		DatabaseInfo& GetDatabaseInfo();
		bool GetConnectionStatus();

		void Insert(int id, std::string& name, std::string& address, int roll, int _class);	//Create
		void Retrieve(Data::StudentRegistry* registry);	//Retrieve
		void Update(int id, std::string& new_name, std::string& new_address);	//Update
		void Delete(int studentID);	//Delete

		void ClearDatabase();
	};
}

#endif