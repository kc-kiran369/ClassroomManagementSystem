#include"Database/SqlConnector.h"

cms::Database::SqlConnector cms::Database::SqlConnector::instance;

cms::Database::SqlConnector::SqlConnector()
{

}

cms::Database::SqlConnector::~SqlConnector()
{
	delete con;
}

void cms::Database::SqlConnector::ChangeServer(const char* server)
{
	memcpy_s(m_DatabaseInfo.server, sizeof(m_DatabaseInfo.server), server, sizeof(server));
}

void cms::Database::SqlConnector::ChangeUser(const char* user)
{
	memcpy_s(m_DatabaseInfo.username, sizeof(m_DatabaseInfo.username), user, sizeof(user));
}

void cms::Database::SqlConnector::ChangPassword(const char* password)
{
	memcpy_s(m_DatabaseInfo.password, sizeof(m_DatabaseInfo.password), password, sizeof(password));
}

void cms::Database::SqlConnector::ChangDatabase(const char* database)
{
	memcpy_s(m_DatabaseInfo.database, sizeof(m_DatabaseInfo.database), database, sizeof(database));
}

void cms::Database::SqlConnector::ChangeTable(const char* table)
{
	memcpy_s(m_DatabaseInfo.table, sizeof(m_DatabaseInfo.table), table, sizeof(table));
}

void cms::Database::SqlConnector::Connect()
{
	try
	{
		this->driver = get_driver_instance();
		this->con = driver->connect(m_DatabaseInfo.server, m_DatabaseInfo.username, m_DatabaseInfo.password);
		con->setSchema(m_DatabaseInfo.database);
		cms::Windows::PromptBox::Open("Connection with database established", MB_OK | MB_ICONINFORMATION);
		stmt = con->createStatement();
	}
	catch (sql::SQLException e)
	{
		cms::Windows::PromptBox::Open(e.what(), MB_OK | MB_ICONEXCLAMATION);
		cms::Windows::PromptBox::Open("Any changes will not be uploaded in database", MB_OK | MB_ICONEXCLAMATION);
	}
}

cms::Database::DatabaseInfo& cms::Database::SqlConnector::GetDatabaseInfo()
{
	return m_DatabaseInfo;
}

bool cms::Database::SqlConnector::GetConnectionStatus()
{
	return (con ? true : false);
}

void cms::Database::SqlConnector::Insert(int id, std::string& name, std::string& address, int roll, int _class)
{
	if (con)
	{
		try
		{
			std::string table = m_DatabaseInfo.table;
			res = stmt->executeQuery("INSERT INTO " + table + "(StudentID,Name, Address, Roll, Class) VALUES(" + std::to_string(id) + ",\'" + name + "\', \'" + address + "\'," + std::to_string(roll) + "," + std::to_string(_class) + ")");
		}
		catch (sql::SQLException e) {}
	}
}

void cms::Database::SqlConnector::Retrieve(Data::StudentRegistry* registry)
{
	if (con)
	{
		try
		{
			std::string table = m_DatabaseInfo.table;
			res = stmt->executeQuery("SELECT* FROM " + table);

			int rowCount = (int)res->rowsCount();
			if (rowCount == 0)
			{
				Windows::PromptBox::Open("Database is empty", MB_OK | MB_ICONINFORMATION);
				return;
			}

			while (res->next()) {
				UINT id = res->getUInt(1);
				UINT roll = res->getUInt(2);
				std::string name = res->getString(3);
				std::string address = res->getString(4);
				UINT class_ = res->getUInt(5);

				switch (class_)
				{
				case (UINT)Data::CLASS::NINE:
					registry->Class09.AddStudent(name, roll, address, (UINT)Data::CLASS::NINE, Data::StudentAdditionType::DATABASE);
					break;
				case (UINT)Data::CLASS::TEN:
					registry->Class10.AddStudent(name, roll, address, (UINT)Data::CLASS::TEN, Data::StudentAdditionType::DATABASE);
					break;
				case (UINT)Data::CLASS::ELEVEN:
					registry->Class11.AddStudent(name, roll, address, (UINT)Data::CLASS::ELEVEN, Data::StudentAdditionType::DATABASE);
					break;
				case (UINT)Data::CLASS::TWELVE:
					registry->Class12.AddStudent(name, roll, address, (UINT)Data::CLASS::TWELVE, Data::StudentAdditionType::DATABASE);
					break;
				};
			}
			std::string msg = std::to_string(rowCount) + " rows retrieved";
			Windows::PromptBox::Open(msg.c_str(), MB_OK | MB_ICONINFORMATION);
		}
		catch (sql::SQLException e) {}
	}
}

void cms::Database::SqlConnector::Update(int id, std::string& new_name, std::string& new_address)
{
	if (con)
	{
		try
		{
			std::string table = m_DatabaseInfo.table;
			res = stmt->executeQuery("UPDATE " + table + "SET Name = \'" + new_name + "\', Address = \'" + new_address + "\' WHERE StudentID = " + std::to_string(id));
		}
		catch (sql::SQLException e) {}
	}
}

void cms::Database::SqlConnector::Delete(int studentID)
{
	if (con)
	{
		try
		{
			std::string table = m_DatabaseInfo.table;
			res = stmt->executeQuery("DELETE FROM \'" + table + "\' WHERE StudentID = \'" + std::to_string(studentID) + "\'");
		}
		catch (sql::SQLException e) {}
	}
}

void cms::Database::SqlConnector::ClearDatabase()
{
	if (con)
	{
		try
		{
			std::string table = m_DatabaseInfo.table;
			res = stmt->executeQuery("DELETE* FROM " + table);
		}
		catch (sql::SQLException e) {}
	}
}