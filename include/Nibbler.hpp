//
// EPITECH PROJECT, 2018
// 
// File description:
// 

#ifndef NIBBLER_HPP_
# define NIBBLER_HPP_

#include "IGame.hpp"
#include <iostream>
#include <vector>

class		Nibbler : public IGame
{
public:
	Nibbler();
	~Nibbler() {}
	void					loadMap();
	void					popFruit();
	void					popSerpent();
	void					ChangeDirection(int event);
	virtual bool					getEnd() const;
	virtual std::vector<std::string>		getMap() const;
	virtual bool					getEat() const;
	virtual std::string				getHighScore() const;
	virtual void					move(int dir);
	virtual int					getScore() const;
	virtual int					getGame() const;
	void					Fruit();
	bool					checkMove(unsigned int y, unsigned int x);
	void					loadHighScore();
private:
	int				event;
	int				pos_x;
	int				pos_y;
	std::vector<std::string>	_nibblerMap;
	std::vector<int>		_nibbler_x;
	std::vector<int>		_nibbler_y;
	int				_score;
	std::string			_highScore;
	bool				_eat;
	bool				_end;
	int				_dir;
};

#endif
