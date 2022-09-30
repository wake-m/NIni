# NIni - 一个简单，轻量，跨平台的ini解析器
使用方法
如果ini文件是是这样的
```
bc=true
[server]
ip=127.0.1
port = 80
[user]
password=iss
```
那么解析它们的代码是这样的
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
