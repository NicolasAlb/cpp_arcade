//
// EPITECH PROJECT, 2018
// Ngameover
// File description:
// src
//

#include "NMenu.hpp"

int		NMenu::gameOver()
{
	int	c = 0;

	this->printGO();
	this->printInfoGO();
	while (42) {
		c = getch();
		switch (c) {
		case 114:
			return (RES_PAC);
			break;
		case 101:
			endwin();
			exit(0);
			break;
		case 109:
			return (-1);
			break;
		}
	}
}
