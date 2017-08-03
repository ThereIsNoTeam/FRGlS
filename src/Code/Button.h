#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button();
	Button(std::wstring path);
	//virtual void OnClick() &;								
private:
	int gamestate;											//Na jakim gamestate button jest aktywny
	sf::Texture textures[3];
	sf::Sprite sprites[3];									//3 obrazki dla nieaktywnego, najechanegho i wciœniêtego
};
