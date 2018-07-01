//
// EPITECH PROJECT, 2018
// arcade
// File description:
// pacman include
//

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include "../include/IGame.hpp"

class	Pacman : public IGame
{
	std::vector<std::string>				_map;
	int							_posG[3][3];
	int							_posx;
	int							_posy;
	int							_score;
	bool							_end;
	std::chrono::time_point<std::chrono::system_clock>	_startTG;
	std::chrono::time_point<std::chrono::system_clock>	_startTP;
	bool							_takeP;
	bool							_launch;
	bool							_eat;
	std::string						_highScore;
public:
	Pacman();
	virtual ~Pacman();
	virtual std::vector<std::string>			getMap() const;
	virtual int						getScore() const;
	virtual std::string					getHighScore() const;
	virtual bool						getEnd() const;
	virtual bool						getEat() const;
	virtual int						getGame() const;
	void							loadHighScore();
	void							loadMap();
	void							addPacman();
	void							addGhosts();
	void							moveGhosts();
	void							moveIa(int);
	void							runAway(int);
	void							moveRandom(int);
	void							game();
	void							GUp(int);
	void							GDown(int);
	void							GLeft(int);
	void							GRight(int);
	void							moveUp();
	void							moveDown();
	void							moveLeft();
	void							moveRight();
	virtual void						move(int);
	bool							checkMove(int, int);
	void							checkGhosts();
	int							checkFruit(int, int);
	bool							checkGhost(int, int);
	bool							checkTimeG();
	bool							checkTimeP();
};

#endif
