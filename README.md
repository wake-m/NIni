NINI is a simple, lightweight cross-platform INI parser
使用方法
If the ini file is like this
```
bc=true
[server]
ip=127.0.1
port = 80
[user]
password=iss
```
Then the code that parses them looks like this
```
#include<iostream>
#include"Ini.h"

using namespace std;

int main() {
	Ini Config;

	Config.PointToFile(".\\config.ini");


	bool bc = Config[""]["bc"];

	string ip = Config["server"]["ip"];

	int port = Config["server"]["port"];
	
	string password = Config["user"]["password"];

	return 0;
}


```
When you modify the contents of the ini class you need to function RefFile() to refresh the contents of the file
```
//The contents of the file do not change
Config[""]["bc"] = "false";
//Now the contents of the file change
Config.RefFile();
```

