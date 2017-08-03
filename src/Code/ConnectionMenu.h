#pragma once
#include <memory>
#include <fstream>
#include "Button.h"
#include <SFML/Network.hpp>
class ConnectionMenu
{
public:
	ConnectionMenu();
	ConnectionMenu(std::shared_ptr<sf::TcpSocket> socket, std::shared_ptr<std::wofstream> ptr, std::wstring address = L"", std::wstring username = L"", std::wstring password = L"");
	~ConnectionMenu();																//Nie jestem pewien czy nie trzeba siê roz³¹czyæ
	ConnectionMenu& operator=(ConnectionMenu&) &;
	ConnectionMenu& operator=(ConnectionMenu&&) &;
	void Connect();																	//Myœla³em o prze³adowaniu jakiegoœ operatora
private:
	std::shared_ptr<sf::TcpSocket> socket;
	std::shared_ptr<std::wofstream> logFile;										
	std::wstring address, username, password;										//Dane potrzebne do logowania. Has³o ma byæ hashowane.
	Button buttons[2];																//Przyciski: po³¹cz i anuluj
};
