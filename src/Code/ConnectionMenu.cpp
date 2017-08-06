#include "ConnectionMenu.h"
#include "Exceptions.h"
using std::swap;

void swap(ConnectionMenu& a, ConnectionMenu& b)
{
	swap(a.address, b.address);
	swap(a.username, b.username);
}

ConnectionMenu::ConnectionMenu(std::shared_ptr<sf::UdpSocket> socket, std::shared_ptr<std::wofstream> ptr, std::wstring address, std::wstring username, std::wstring password) : socket(socket), logFile(ptr), address(address), username(username), password(password)
{
	
}

ConnectionMenu::~ConnectionMenu()
{
	
}

ConnectionMenu& ConnectionMenu::operator=(const ConnectionMenu &assg) &
{
	this->logFile = assg.logFile;
	this->address = assg.address;
	this->username = assg.username;
	return *this;
}

ConnectionMenu& ConnectionMenu::operator=(ConnectionMenu&& assg) &
{
	this->logFile = assg.logFile;
	std::swap(assg, *this);
	return *this;
}

void ConnectionMenu::Connect() 
{
	if (!socket) throw w_err(L"Error!\n Socket wasn't initialized properly");
}