//
// EPITECH PROJECT, 2018
// menu_sf
// File description:
// header
//

#ifndef MENU_SF_HPP_
# define MENU_SF_HPP_

#include <dirent.h>
#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include <dlfcn.h>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include "IGraphics.hpp"
#include "IGame.hpp"

class	Manager
{
	enum LIBS {
		L_SF,
		L_NC
	};

public:
	Manager(char **av);
	virtual ~Manager() = default;
	void				loadLib(std::string);
	void				loadLibs(std::string path);
	void				loadGame(std::string game);
	void				changeLib();
	void				update_lib(std::string lib);
	int				main_loop_pacman();
	int				main_loop_nibbler();
	IGraphics			*getLib() { return (_lib); }
	
private:
	std::vector<std::string>	_lib_list;
	IGraphics			*_lib;
	IGame				*_game;
	unsigned int			lib;
	LIBS				current_lib;
};

void				coreLoop(Manager &manager);
void				put_error(void);
void				lib_error(void);

#endif /* !MENU_SF_HPP_ */
