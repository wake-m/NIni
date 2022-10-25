#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include"Value.h"
#include<ios>
#include<vector>



#ifndef INI_H
#define INI_H



typedef std::map<std::string, std::map<std::string, Value>> key_key_value;
typedef std::map<std::string, Value> key_value;


class Ini
{
public:
	Ini();
	~Ini();
	bool PointToFile(const std::string& filename);
	void close();
	bool empty();
	std::string GetConfigFile();
	key_value& operator[](std::string s);
	void RefFile();
private:
	
	std::string ConfigFile;
	key_key_value all_data;

};
#endif // !INI_Hs



