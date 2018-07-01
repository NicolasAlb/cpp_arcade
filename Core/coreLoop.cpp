//
// EPITECH PROJECT, 2018
// coreLoop
// File description:
// src
//

#include "menu_sf.hpp"
#include "NMenu.hpp"
#include "SMenu.hpp"


void		coreLoop(Manager &manager)
{
	int	event = 0;

	event = manager.getLib()->menu();
	switch (event) {
	case CHANGE_LIB:
		manager.changeLib();
		break;
	case PAC_L:
		if (manager.main_loop_pacman() == BACK_MENU)
			coreLoop(manager);
		break;
	case NIB_L:
		if (manager.main_loop_nibbler() == BACK_MENU)
			coreLoop(manager);
		break;
	}
}

int		Manager::main_loop_pacman(void)
{
	int	ev = 0;
	
	this->loadGame("./games/lib_arcade_pacman.so");
	ev = this->_lib->draw(this->_game);
	switch (ev) {
	case RES_PAC:
		while (ev == RES_PAC) {
			this->loadGame("./games/lib_arcade_pacman.so");
			ev = this->_lib->draw(this->_game);
		}
		break;
	case CHANGE_G:
		this->main_loop_nibbler();
		break;
	case CHANGE_LIB:
		this->changeLib();
		this->main_loop_pacman();
		break;
	case BACK_MENU:
		return (BACK_MENU);
		break;
	}
	return (ev);
}

int		Manager::main_loop_nibbler(void)
{
	int	ev = 0;
	
	this->loadGame("./games/lib_arcade_nibbler.so");
	ev = this->_lib->draw(this->_game);
	switch (ev) {
	case RES_PAC:
		
		while (ev == RES_PAC) {
			this->loadGame("./games/lib_arcade_nibbler.so");
			ev = this->_lib->draw(this->_game);
		}
		break;
	case CHANGE_G:
		this->main_loop_pacman();
		break;
	case CHANGE_LIB:
		this->changeLib();
		this->main_loop_nibbler();
		break;
	case BACK_MENU:
		return (BACK_MENU);
		break;
	}
	return (ev);
}
