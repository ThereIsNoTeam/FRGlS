#pragma once
#include <fstream>
#include <memory>
#include <vector>
#include "ConnectionMenu.h"
#include "MultiTextBox.h"
#include "Exceptions.h"

class Cmain
{
public:
	Cmain();
	std::shared_ptr<std::wofstream> logFile;							//Plik z logami, je¿eli bêdziemy bawiæ siê w wielow¹tkowoœæ to trzeba z tym uwa¿aæ							
	int FirstConnectLoop() noexcept;									//Menu kiedy gracz jeszcze siê nie po³¹czy³ z ¿adnym serwerem. Powinniœmy zadbaæ, ¿eby rzeczywiœcie funkcja by³a noexcept								
	int GameLoop();														//G³ówna pêtla gry
private:
	std::vector<ConnectionMenu> connections;							//Gracz mo¿e sobie generowaæ ró¿ne okienka
	sf::RenderWindow window;											//Okno gry, na nim s¹ renderowane obrazki
	sf::Event mainevent;												//Przetwarza input uzytkownika
	std::shared_ptr<sf::TcpSocket> socket 
		= std::shared_ptr<sf::TcpSocket>(new sf::TcpSocket);			//Zapewnia po³¹czenie miêdzy serwerem a graczem
	enum class gamestate {CONNECT, MENU, PLAY};							//Zale¿nie od tego niektóre elementy dzia³aj¹ w ró¿ny sposób; CONNECT = 0, MENU = 1, PLAY = 2
	bool running = true;												//Zmiana tej wartoœci koñczy dzia³anie programu
};
