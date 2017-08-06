#pragma once
#include <string>
#include <map>
#include <fstream>
#include <memory>

class INIReader
{
public:
	INIReader(std::shared_ptr<std::wofstream> logFile, const std::wstring &path, std::map<const std::string, std::map<const std::string, void*>> &vals) : logFile(logFile) { read(path, vals); };
private:
	void read(const std::wstring &path, std::map<const std::string, std::map<const std::string, void*>> &vals);
	std::shared_ptr<std::wofstream> logFile;																				//Plik z logami
};