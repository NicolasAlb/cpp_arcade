//
// EPITECH PROJECT, 2018
// NKeyboard
// File description:
// src
//

#include "NMenu.hpp"

void		NMenu::quit(void)
{
	endwin();
	exit(0);
}

int		NMenu::select()
{
	switch (_pos) {
	case EXIT:
		endwin();
		exit(0);
		break;
	case PACMAN:
		return (PAC_L);
		break;
	case NIBBLER:
		return (NIB_L);
		break;
	}
	return (-1);
}

int		NMenu::Kevent(int ch)
{
	int	return_value = 0;
	
	switch (ch) {
	case 10:
		return_value = this->select();
		if (return_value != -1)
			return (return_value);
		break;
	case 101:
		this->quit();
		break;
	case KEY_UP:
		this->Up();
		break;
	case KEY_DOWN:
		this->Down();
		break;
	case 98:
		return (CHANGE_LIB);
		break;
	case 110:
		return (CHANGE_LIB);
		break;
	}
	return (0);
}

