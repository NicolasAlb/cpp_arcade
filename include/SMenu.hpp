//
// EPITECH PROJECT, 2018
// SMenu
// File description:
// header
//

#ifndef SMENU_HPP_
# define SMENU_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <dlfcn.h>
#include <iostream>
#include "IGraphics.hpp"
#include "IGame.hpp"

class	SMenu : public IGraphics
{
	enum Event
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
public:
	SMenu();
	virtual ~SMenu() = default;
	void				Up();
	void				Down();
	virtual int			menu();
	virtual void			drawMenu();
	virtual int			draw(IGame *);
	void				printAll(sf::RenderWindow &w);
	void				printPacman(sf::RenderWindow &w);
	void				printNibbler(sf::RenderWindow &w);
	void				printExit(sf::RenderWindow &w);
	void				quit(sf::RenderWindow &w);
	int				select(sf::RenderWindow &w);
	int				getPos() const { return (_pos); };
	int				getLib() const { return (_menuLib); };
	void				setPos(int pos) { _pos = pos; };
	void				setLib(int lib) { _menuLib = lib; };
	int				Kevent(sf::RenderWindow &w);
	void				loadLibs(std::string path);
	void				loadGames(std::string path);
	void				init_Info();
	void				init_menu();
	void				setMap(const std::vector<std::string>);
	void				drawMap(IGame *);
	void				print_info();
	void				print_info2();
	void				D_wall(int, int);
	void				D_powerUps(int, int);
	void				D_fruit(int, int);
	void				D_pacR(int, int);
	void				D_pacD(int, int);
	void				D_pacL(int, int);
	void				D_pacU(int, int);
	void				D_ghost(int, int);
	void				D_ghostE(int, int);
	void				D_space(int, int);
	virtual int			gameOver();
	int				win();
	bool				checkWin();
	void				D_nibblerR(int, int);
	void				D_nibblerU(int, int);
	void				D_nibblerD(int, int);
	void				D_nibblerB(int, int);
	void				D_nibblerL(int, int);
	void				D_nibblerF(int, int);
	void				addHighScore();
protected:
	std::vector<std::string>	_map;
	sf::RenderWindow		*_win;
	Event				_dir;
	std::string			_score;
	std::string			_highScore;
	sf::Font			_menuFont;
	sf::Text			_menu[3];
	sf::Text			_menuInfo[5];
	sf::Event			_event;
	int				_menuLib;
	int				_pos;
	int				_g;
	std::vector<std::string>	_lib_list;
	std::vector<std::string>	_game_list;
	IGraphics			*_lib;
	IGame				*_game;
};

#endif /* !SMENU_HPP_ */
