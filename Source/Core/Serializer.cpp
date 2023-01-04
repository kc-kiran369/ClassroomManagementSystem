#include"Core/Serializer.h"

cms::Core::Serializer cms::Core::Serializer::instance;

//Private methods
std::string cms::Core::Serializer::GetValue(std::string& key)
{
	std::ifstream in;
	in.open("config_app.cms", std::ios::in);
	if (in.fail()) {
		CreateConfigFile();
		in.open("config_app.cms", std::ios::in);
	}
	std::string line;
	while (std::getline(in, line))
	{
		if (line.find(key) != std::string::npos)
		{
			in.close();
			return line.erase(0, key.length() + 1);
		}
	}
	in.close();
	return "NULL";
}

void cms::Core::Serializer::CreateConfigFile()
{
	std::ofstream out("config_app.cms");
	out << "width:1000\nheight:600\nfont_size:17\napp_name:Classroom Management (64-bit, windows)" << std::endl;
	out.close();
}

//Public methods
int cms::Core::Serializer::GetInt(std::string key)
{
	std::string val = GetValue(key);
	return (val == "NULL" ? VALUE_NOT_FOUND : std::stoi(val));
}

float cms::Core::Serializer::GetFloat(std::string key)
{
	std::string val = GetValue(key);
	return (val == "NULL" ? VALUE_NOT_FOUND : std::stof(val));
}

std::string cms::Core::Serializer::GetString(std::string key)
{
	std::string val = GetValue(key);
	return val;
}