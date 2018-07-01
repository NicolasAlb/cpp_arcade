//
// EPITECH PROJECT, 2018
// SKeyboard
// File description:
// src
//

#include "SMenu.hpp"

void	SMenu::quit(sf::RenderWindow &w)
{
	w.close();
	exit(0);
}

int	SMenu::select(sf::RenderWindow &w)
{
	if (_pos == EXIT) {
		w.close();
		exit(0);
	}
	else if (_pos == PACMAN) {
		w.close();
		return (PAC_L);
	}
	else if (_pos == NIBBLER) {
		w.close();
		return (NIB_L);
	}
	return (-1);
}

int	SMenu::Kevent(sf::RenderWindow &w)
{
	int		return_value = 0;
	
	if (_event.type == sf::Event::KeyReleased) {
		if (_event.key.code == sf::Keyboard::Up)
			this->Up();
		else if (_event.key.code == sf::Keyboard::Down)
			this->Down();
		else if (_event.key.code == sf::Keyboard::B) {
			w.close();
			return (CHANGE_LIB);
		}
		else if (_event.key.code == sf::Keyboard::N) {
			w.close();
			return (CHANGE_LIB);
		}
		else if (_event.key.code == sf::Keyboard::E)
			this->quit(w);
		else if (_event.key.code == sf::Keyboard::Return) {
			return_value = this->select(w);
			if (return_value != -1)
				return (return_value);
		}
	}
	else if (_event.type == sf::Event::Closed) {
		w.close();
		exit(0);
	}
	return (0);
}
