#include "Cmain.h"
constexpr int MAX_LOGS_STORED = 10;

Cmain::Cmain()
{
	if (std::ifstream("../../bin/logs/10.txt"))
	if (std::remove("../../bin/logs/10.txt")) 
		warn(L"Old logs couldn't be deleted. FRGlS probably hasn't proper file access to do this operation");
	for (int x = MAX_LOGS_STORED - 1; x != 0; --x)
	{
		std::string oldname, newname = oldname = "../../bin/logs/";
		oldname += std::to_string(x); oldname += ".txt";
		newname += std::to_string(x + 1); newname += ".txt";
		std::rename(oldname.c_str(), newname.c_str());
	};
		logFile = std::shared_ptr<std::wofstream>(new std::wofstream(L"../../bin/logs/1.txt"));

	//std::wstring address, username, password;
	/*
	INIReader dla connect
	*/
	//ConnectionMenu connect(socket, logFile, address, username);
	int width = 800, height = 600; //int soundvolume_example = std::size("Default value in case reading failed");

	INIReader options_i(logFile, L"../../bin/Options.ini", {
		{
			"[Graphics]",{ { "iWidth", &width },{ "iHeight", &height } }
		}/*,
		{
			"[Audio_example]",{ { "iVolume", &soundvolume_example } }
		}*/
	});
	window.create(sf::VideoMode(width, height), L"FRGlS", sf::Style::Resize | sf::Style::Close);
}		