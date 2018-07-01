//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <unistd.h>
#include <curses.h>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Nibbler.hpp"

extern "C" IGame*	create()
{
	return new Nibbler;
}

Nibbler::Nibbler() :
	event(4), _score(0), _end(false), _dir(3)
{
	loadMap();
	loadHighScore();
}


bool	Nibbler::getEat() const
{
	return (_eat);
}

int		Nibbler::getScore() const
{
	return _score;
}

int		Nibbler::getGame() const
{
	return (1);
}

std::string	Nibbler::getHighScore() const
{
	return (_highScore);
}

void		Nibbler::Fruit()
{
	int	y = 0;
	int	x = 0;
	srand(time(NULL));
	while (_nibblerMap[y][x] != ' ') {
		y = rand() % 28 + 1;
		x = rand() % 28 + 1;
	}
	_nibblerMap[y][x] = 'f';
}

void		Nibbler::popSerpent()
{
	_nibbler_x.push_back(15);
	_nibbler_x.push_back(14);
	_nibbler_x.push_back(13);
	_nibbler_x.push_back(12);
	_nibbler_y.push_back(10);
	_nibbler_y.push_back(10);
	_nibbler_y.push_back(10);
	_nibbler_y.push_back(10);
	_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] = '>';
	_nibblerMap[_nibbler_y[1]][_nibbler_x[1]] = 'o';
	_nibblerMap[_nibbler_y[2]][_nibbler_x[2]] = 'o';
	_nibblerMap[_nibbler_y[3]][_nibbler_x[3]] = 'o';
}

void		Nibbler::loadMap()
{
	std::string	line;
	std::ifstream	file("./ressources/NibblerMap", std::ifstream::in | std::ifstream::out);

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			_nibblerMap.push_back(line);
		}
		file.close();
	}
	popSerpent();
	Fruit();
	Fruit();
	Fruit();
	Fruit();
	Fruit();
}

bool		Nibbler::getEnd() const
{
	return _end;
}

void    Nibbler::loadHighScore()
{
	std::ifstream   file("ressources/HighScoreN");

	if (file) {
		getline(file, _highScore);
		file.close();
	}
}


bool		Nibbler::checkMove(unsigned int y, unsigned int x)
{
       	if (_nibblerMap.size() >= y && _nibblerMap[y].size() >= x)
		if (_nibblerMap[y][x] == '#' || _nibblerMap[y][x] == 'o')
			return false;
	return true;
}

void				Nibbler::move(int dir)
{
	unsigned int	old_y, old_x, new_y, new_x = 0;
	unsigned int	cpt = -1;
	unsigned int	fruit;

	if (dir == 3)
	{
		if (!(_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] == '>') && _nibblerMap[_nibbler_y[0]][_nibbler_x[0]] != '<')
			_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] = '>';
		new_x = _nibbler_x[0] + 1;
		new_y = _nibbler_y[0];
	}
	if (dir == 2)
	{
		if (!(_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] == '<') && _nibblerMap[_nibbler_y[0]][_nibbler_x[0]] != '>')
			_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] = '<';
		new_x = _nibbler_x[0] - 1;
		new_y = _nibbler_y[0];
	}
	if (dir == 0)
	{
		if (!(_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] == '^') && _nibblerMap[_nibbler_y[0]][_nibbler_x[0]] != 'v')
			_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] = '^';
		new_x = _nibbler_x[0];
		new_y = _nibbler_y[0] - 1;
	}
	if (dir == 1)
	{
		if (!(_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] == 'y') && _nibblerMap[_nibbler_y[0]][_nibbler_x[0]] != '^')
			_nibblerMap[_nibbler_y[0]][_nibbler_x[0]] = 'y';
		new_x = _nibbler_x[0];
		new_y = _nibbler_y[0] + 1;
	}

	if (checkMove(new_y, new_x) == false)
		_end = true;
	while (++cpt < _nibbler_x.size())
	{
		old_x = _nibbler_x[cpt];
		old_y = _nibbler_y[cpt];
		if (_nibblerMap[new_y][new_x] == 'f') {
			Fruit();
			fruit = 1;
			_score += 10;
		}
		_nibblerMap[new_y][new_x] = _nibblerMap[old_y][old_x];
		_nibbler_x[cpt] = new_x;
		_nibbler_y[cpt] = new_y;
		_nibblerMap[old_y][old_x] = 'o';
		if (cpt == _nibbler_x.size() - 1)
			_nibblerMap[old_y][old_x] = ' ';
		new_x = old_x;
		new_y = old_y;
	}
	if (fruit == 1) {
		_nibbler_x.push_back(old_x);
		_nibbler_y.push_back(old_y);
		_nibblerMap[old_y][old_x] = 'o';
	}
}

std::vector<std::string>	Nibbler::getMap() const
{
	return _nibblerMap;
}
