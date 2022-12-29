#include"Core/Serializer.h"

Serializer Serializer::instance;

//For internal purpose
std::string Serializer::GetValue(std::string& key)
{
	std::ifstream in("config_app.cms", std::ios::in);

	if (in.fail()) {
		CreateConfigFile();
	}

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

void Serializer::CreateConfigFile()
{
	std::ofstream out;
	out.open("config_app.cms");
	out << "width:1000\nheight:600\nui_scale:1.2\nsystem_console:false" << std::endl;
	out.close();
}

int Serializer::GetInt(std::string key)
{
	std::string val = GetValue(key);
	return (val == "NULL" ? VALUE_NOT_FOUND : std::stoi(val));
}

float Serializer::GetFloat(std::string key)
{
	std::string val = GetValue(key);
	return (val == "NULL" ? VALUE_NOT_FOUND : std::stof(val));
}

std::string Serializer::GetString(std::string key)
{
	std::string val = GetValue(key);
	return val;
}
//
//void Serializer::SetInt(std::string key, int value)
//{
//	
//}
//
//void Serializer::SetFloat(std::string key, float value)
//{
//
//}
//
//void Serializer::SetString(std::string key, std::string value)
//{
//
//}
