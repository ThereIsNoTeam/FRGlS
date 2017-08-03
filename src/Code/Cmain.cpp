#include "Cmain.h"

Cmain::Cmain()
{
	std::wstring address, username, password;
	/*
	std::getline(savedAddress, address);
	std::getline(savedAddress, username);
	//opcjonalnie has³o te¿
	*/
	ConnectionMenu connect(socket, logFile, address, username);
}		