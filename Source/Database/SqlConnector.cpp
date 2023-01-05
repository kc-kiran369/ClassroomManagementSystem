#include"Database/SqlConnector.h"

cms::Database::SqlConnector cms::Database::SqlConnector::instance;

cms::Database::SqlConnector::SqlConnector()
{
	m_DatabaseInfo.server = "127.0.0.1";
	m_DatabaseInfo.username = "root";
	m_DatabaseInfo.password = "";
	m_DatabaseInfo.database = "mydatabase";
	m_DatabaseInfo.table = "student";
}

cms::Database::SqlConnector::~SqlConnector()
{
	delete con;
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
	}
}

cms::Database::DatabaseInfo& cms::Database::SqlConnector::GetDatabaseInfo()
{
	return m_DatabaseInfo;
}

void cms::Database::SqlConnector::Insert(std::string& name, std::string& address, int roll)
{
	if (con)
	{
		try
		{
			res = stmt->executeQuery("INSERT INTO " + m_DatabaseInfo.table + "(FirstName, Lastname, Roll) VALUES(\'" + name + "\', \'" + address + "\'," + std::to_string(roll) + ")");
		}
		catch (sql::SQLException e) {}
	}
}

void cms::Database::SqlConnector::Retrieve()
{

}

void cms::Database::SqlConnector::Update(int roll, std::string& new_name, std::string& new_address)
{
	if (con)
	{
		try
		{

		}
		catch (sql::SQLException e) {}
	}
}

void cms::Database::SqlConnector::Delete(std::string& name, std::string& address, int roll)
{
	if (con)
	{
		try
		{

		}
		catch (sql::SQLException e) {}
	}
}