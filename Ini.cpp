#include "Ini.h"



Ini::Ini() {

}

Ini::~Ini() {

}

key_value& Ini::operator[](std::string s) {
	key_value* temp = &all_data[s];
	return *temp;
}


bool Ini::PointToFile(const std::string& filename) {
	std::ifstream file;
	ConfigFile = filename;
	file.open(this->ConfigFile,std::ifstream::in);
	if (file.is_open()) {
		std::string session;
		std::string line;
		
		while (std::getline(file,line)){
			size_t findcode = line.find('=');
			
			if (line.empty()) {
				session.clear();
				continue;
			}else if (line[0] == '[') {
				session = line.substr(1, line.find(']') - 1);
				continue;
			}

			if (findcode != line.npos) {
				all_data[session][line.substr(0, findcode)] = line.substr(findcode + 1, line.find('\n'));
			}
			else if (findcode == line.npos) {
				close(); 
				return false;
			}
			
		}
	}
	return true;
}




void Ini::RefFile() {
	std::fstream files;
	// π”√∏≤∏«–¥»Î
	files.open(GetConfigFile(),std::ios::out|std::ios::trunc);
	
	if (files.is_open()) {
		for (auto& t : all_data) {
			for (auto& ts : all_data[t.first]) {
				if (t.first.empty()) {
					files << ts.first << "=" << std::string(all_data[t.first][ts.first]) << "\n";
				}
			}	
		}

		std::vector<std::string> s;
		
		for (auto& t : all_data){
			if (t.first == "") continue;
			std::string temp = "[";
			temp.append(t.first).append("]").append("\n");
			for (auto& ts : all_data[t.first]) {
				temp.append(ts.first).append("=").append(all_data[t.first][ts.first]).append("\n");
			}
			s.push_back(temp),temp.clear();
		}
		
		for (std::string tm : s) {
			files << tm << "\n";
		}
	}

	files.close();
}

std::string Ini::GetConfigFile() {
	return ConfigFile;
}


bool Ini::empty() {
	return all_data.empty();
}

void Ini::close() {
	this->ConfigFile.clear();
	this->all_data.clear();
}


