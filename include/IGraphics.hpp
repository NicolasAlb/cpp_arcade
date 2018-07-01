//
// EPITECH PROJECT, 2018
// interface graphique
// File description:
// 
//

#ifndef IGRAPHICS_HPP_
# define IGRAPHICS_HPP_

#include <iostream>
#include <ncurses.h>
#include <dlfcn.h>
#include <vector>
#include <dirent.h>
#include "IGame.hpp"

enum
{
	PACMAN,
	NIBBLER,
	EXIT,
	SFML,
	NCURSE,
	CHANGE_LIB,
	PAC_L,
	NIB_L,
	RES_PAC,
	CHANGE_G,
	BACK_MENU
};

class		IGraphics
{
public:
	virtual ~IGraphics() {};
	virtual	int	menu() = 0;
	virtual void drawMenu() = 0;
	virtual int draw(IGame*) = 0;
};

#endif /* !IGRAPHICS_HPP_ */
