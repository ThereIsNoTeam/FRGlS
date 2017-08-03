#include "ConnectionMenu.h"
#include "Exceptions.h"

ConnectionMenu::ConnectionMenu()
{

}

ConnectionMenu::ConnectionMenu(std::shared_ptr<sf::TcpSocket> socket, std::shared_ptr<std::wofstream> ptr, std::wstring address, std::wstring username, std::wstring password) : socket(socket), logFile(ptr), address(address), username(username), password(password)
{
	
}

ConnectionMenu::~ConnectionMenu()
{
	
}

ConnectionMenu& ConnectionMenu::operator=(ConnectionMenu& assg) &
{
	if (this->logFile != assg.logFile)
		this->logFile = assg.logFile;
	this->address = assg.address;
	this->username = assg.username;
	return *this;
}

ConnectionMenu& ConnectionMenu::operator=(ConnectionMenu&& assg) &
{
	if (this->logFile != assg.logFile)
		this->logFile = assg.logFile;
	this->address = assg.address;
	this->username = assg.username;
	return *this;
}

void ConnectionMenu::Connect() 
{
	if (!socket) throw w_err(L"Error!\n Socket wasn't initialized properly");
}