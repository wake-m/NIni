#ifndef INI_H
#define INI_H
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include"Value.h"

typedef std::map<std::string, std::map<std::string, Value>> key_key_value;
typedef std::map<std::string, Value> key_value;


class Ini
{
public:
	Ini();
	~Ini();
	void PointToFile(const std::string& filename);

	key_value operator[](std::string s);
private:
	std::string ConfigFile;
	key_key_value all_data;

};
#endif // !INI_H



