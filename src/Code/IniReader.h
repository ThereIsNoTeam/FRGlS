#pragma once
#include <string>
#include <map>
#include <fstream>
#include <memory>

class INIReader
{
public:
	INIReader(std::shared_ptr<std::wofstream> logFile, const std::wstring &path, const std::map<const std::string, const std::map<const std::string, void*>> &vals) : logFile(logFile) { read(path, vals); };
	void read(const std::wstring &path, const std::map<const std::string, const std::map<const std::string, void*>> &vals);
private:
	std::shared_ptr<std::wofstream> logFile;																				//Plik z logami
};