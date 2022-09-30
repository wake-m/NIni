#include "Ini.h"



Ini::Ini() {

}

Ini::~Ini() {

}

key_value Ini::operator[](std::string s) {
	
	return this->all_data[s];
}


void Ini::PointToFile(const std::string& filename) {
	std::ifstream file;
	ConfigFile = filename;

	file.open(this->ConfigFile,std::ifstream::in);
	

	if (file.is_open()) {
		std::string section;
		std::string line;
		
		while (std::getline(file,line))
		{
			int findcode = line.find('=');
			
			if (line.empty()) {
				section = "";
			}else if (line.at(0) == '[') {
				int end = line.find(']');
				section = line.substr(1, end - 1);
			}

			if (findcode != line.npos) {
				std::string key;
				Value value;
				key = line.substr(0, findcode);
				value = line.substr(findcode+1, line.find('\n'));
				this->all_data[section][key] = value;
			}
			
		}
	
	}


}