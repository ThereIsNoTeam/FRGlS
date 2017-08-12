#pragma once
#include <fstream>
#include <memory>
#include <vector>
#include "ConnectionMenu.h"
#include "MultiTextBox.h"
#include "Exceptions.h"
#include "INIReader.h"

class Cmain
{
public:
	Cmain();
	std::shared_ptr<std::wofstream> logFile;							//Plik z logami, je�eli b�dziemy bawi� si� w wielow�tkowo�� to trzeba z tym uwa�a�.							
	int FirstConnectLoop() noexcept;									//Menu kiedy gracz jeszcze si� nie po��czy� z �adnym serwerem. Powinni�my zadba�, �eby rzeczywi�cie funkcja by�a noexcept								
	int GameLoop();														//G��wna p�tla gry
private:
	std::vector<ConnectionMenu> connections;							//Gracz mo�e sobie generowa� r�ne okienka
	sf::RenderWindow window;											//Okno gry, na nim s� renderowane obrazki
	sf::Event mainevent;												//Przetwarza input uzytkownika
	std::shared_ptr<sf::UdpSocket> socket 
		= std::shared_ptr<sf::UdpSocket>(new sf::UdpSocket);			//Zapewnia po��czenie mi�dzy serwerem a graczem
	enum class gamestate {CONNECT, MENU, PLAY};							//Zale�nie od tego niekt�re elementy dzia�aj� w r�ny spos�b; CONNECT = 0, MENU = 1, PLAY = 2
	bool running = true;												//Zmiana tej warto�ci ko�czy dzia�anie programu
};
