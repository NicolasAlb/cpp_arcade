//
// EPITECH PROJECT, 2018
// draw_menu_sf
// File description:
// header
//

#include "SMenu.hpp"

extern "C" IGraphics* create()
{
	return new SMenu;
}

int	SMenu::menu()
{
	sf::RenderWindow	w(sf::VideoMode(1920, 1080), "ARCADE");
	int			event = 0;
	sf::Music		music;

	music.openFromFile("ressources/Sirtaki.ogg");
	music.play();
	this->printAll(w);
	while (w.waitEvent(_event)) {
		event = this->Kevent(w);
		if (event == CHANGE_LIB) {
			return (CHANGE_LIB);
		}
		else if (event == PAC_L || event == NIB_L) {
			w.close();
			return (event);
		}
		this->printAll(w);
	}
	return (0);
}
