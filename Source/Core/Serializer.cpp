#include"Core/Serializer.h"

Serializer Serializer::instance;


//For internal purpose
std::string Serializer::GetValue(std::string& key)
{
	std::ifstream in("config_app.cms", std::ios::in);
	std::string line;
	while (std::getline(in, line))
	{
		if (line.find(key) != std::string::npos)
		{
			return line.erase(0, key.length() + 1);
			in.close();
		}
	}
	in.close();
	return "NULL";
}

int Serializer::GetInt(std::string key)
{
	std::string val = GetValue(key);
	if (val == "NULL")
	{
		return VALUE_NOT_FOUND;
	}
	else
	{
		return std::stoi(val);
	}
}

float Serializer::GetFloat(std::string key)
{
	std::string val = GetValue(key);
	if (val == "NULL")
	{
		return VALUE_NOT_FOUND;
	}
	else
	{
		std::stof(val);
	}
}

std::string Serializer::GetString(std::string key)
{

}

void Serializer::SetInt(std::string key, int value)
{
}

void Serializer::SetString(std::string key, float value)
{
}

void Serializer::SetString(std::string key, std::string value)
{
}
