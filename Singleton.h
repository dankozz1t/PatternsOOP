#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Logger
{
	Logger();
	static Logger* obj;
public:
	static Logger* getInstance();
	void sendMessage(string message);
	
};

Logger* Logger::obj = nullptr;

Logger* Logger::getInstance()
{
	if (!obj)
		obj = new Logger();
	return obj;
}

inline void Logger::sendMessage(string message)
{
	ofstream out("log.txt", ios::app);
	out << __DATE__ << " " << __TIME__ << " " << message << endl;
	out.close();
}


