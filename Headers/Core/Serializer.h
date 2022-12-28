#ifndef SERIALIZER_H
#define SERIALIZER_H

#include<iostream>
#include<fstream>
#include<string>

class Serializer
{
private:
	static Serializer instance;
	std::string GetValue(std::string& key);

	// Private constructor to prevent object creation
	Serializer() {}
	// Private copy constructor and assignment operator to prevent copying
	Serializer(const Serializer&) = delete;
	Serializer& operator=(const Serializer&) = delete;

public:
	// Public static method to access the single instance
	static Serializer& Instance() {
		return instance;
	}

	static const short int VALUE_NOT_FOUND = -1;

	int GetInt(std::string key);
	float GetFloat(std::string key);
	std::string GetString(std::string key);
};

#endif
