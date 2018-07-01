//
// EPITECH PROJECT, 2018
// arcade
// File description:
// pacman cpp
//

#include "Pacman.hpp"
#include <fstream>
#include <curses.h>

extern "C" IGame* create()
{
	return new Pacman;
}

std::vector<std::string>	Pacman::getMap() const
{
	return (_map);
}

bool	Pacman::getEnd() const
{
	return (_end);
}

bool	Pacman::getEat() const
{
	return (_eat);
}

void	Pacman::loadMap()
{
	std::string	line;
	std::ifstream	file("ressources/map");
	std::vector<std::string>::iterator it;

	if (file) {
		while (getline(file, line)) {
			_map.push_back(line);
		}
		file.close();
	}
}

void	Pacman::loadHighScore()
{
	std::ifstream	file("ressources/HighScoreP");

	if (file) {
		getline(file, _highScore);
		file.close();
	}
}

int	Pacman::getScore() const
{
	return (_score);
}

int	Pacman::getGame() const
{
	return (0);
}

std::string	Pacman::getHighScore() const
{
	return (_highScore);
}

void	Pacman::addGhosts()
{
	_map[13][14] = '6';
	_map[13][15] = '6';
	_map[13][16] = '6';
	_posG[0][0] = 13;
	_posG[0][1] = 14;
	_posG[0][2] = 0;
	_posG[1][0] = 13;
	_posG[1][1] = 15;
	_posG[1][2] = 0;
	_posG[2][0] = 13;
	_posG[2][1] = 16;
	_posG[2][2] = 0;
}

void	Pacman::addPacman()
{
	_map[1][1] = '{';
	_posx = 1;
	_posy = 1;
}

Pacman::Pacman()
{
	_end = false;
	_score = 0;
	_launch = false;
	_takeP = false;
	_eat = false;
	loadMap();
	loadHighScore();
	addPacman();
	addGhosts();
}

Pacman::~Pacman()
{
	_end = false;
}
