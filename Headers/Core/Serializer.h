#ifndef SERIALIZER_H
#define SERIALIZER_H

#include<iostream>
#include<fstream>
#include<string>

namespace cms::Core
{
	class Serializer
	{
	private:
		static Serializer instance;
		std::string GetValue(std::string& key);

		Serializer() {}
		Serializer(const Serializer&) = delete;
		Serializer& operator=(const Serializer&) = delete;

		void CreateConfigFile();

	public:
		static Serializer& Instance() {
			return instance;
		}

		static const short int VALUE_NOT_FOUND = -1;

		int GetInt(std::string key);
		float GetFloat(std::string key);
		std::string GetString(std::string key);
	};
}

#endif