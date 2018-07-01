//
// EPITECH PROJECT, 2018
// NMenu
// File description:
// header
//

#ifndef NMENU_HPP_
# define NMENU_HPP_

#include <ncurses.h>
#include <dlfcn.h>
#include <iostream>
#include <vector>
#include <map>
#include "Nibbler.hpp"
#include "IGraphics.hpp"
#include "IGame.hpp"

class	NMenu : public IGraphics
{
public:	
	typedef void(NMenu::*ptr)(int, int);
	
        enum Event {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	NMenu();
	virtual ~NMenu() = default;
	virtual int			menu();
	virtual void			drawMenu();
	virtual int			draw(IGame*);
	void				setMap(const std::vector<std::string>);
	void				drawMap();
	void				D_wall(int, int);
	void				D_fruit(int, int);
	void				D_space(int, int);
	void				D_ghost(int, int);
	void				D_powerUps(int, int);
	void				D_pacR(int, int);
	void				D_pacD(int, int);
	void				D_pacL(int, int);
	void				D_pacU(int, int);
	void				D_nibblerU(int, int);
	void				D_nibblerD(int, int);
	void				D_nibblerR(int, int);
	void				D_nibblerL(int, int);
	void				D_nibblerF(int, int);
	void				D_nibblerB(int, int);
	void				Up();
	void				Down();
	void				printAll();
	void				printPacman();
	void				printNibbler();
	void				printExit();
	void				quit();
	int				select();
	int				getPos() const { return (_pos); };
	int				getLib() const{ return (_menuLib); };
	void				setPos(int pos) { _pos = pos; };
	void				setLib(int lib) { _menuLib = lib; };
	int				Kevent(int ch);
	void				loadLibs(std::string path);
	void				loadGames(std::string path);
	void				printInfo();
	void				printInfoG();
	void				printArcade();
	void				printGO();
	void				printInfoGO();
	virtual int			gameOver();

protected:
	int				_menuLib;
	int				_pos;
	std::vector<std::string>	_lib_list;
	std::vector<std::string>	_game_list;
	IGraphics			*_lib;
	IGame				*_game;
	std::vector<std::string>        _map;
	std::map<char, ptr>		draw_func;
	WINDOW				*_win;
	Event				_dir;

};

#endif /* !NMENU_HPP_ */
