//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef IGAME_HPP_
# define IGAME_HPP_

class		IGame
{
public:
	virtual	~IGame() {};
	virtual	std::vector<std::string>		getMap() const = 0;
	virtual int				getScore() const = 0;
	virtual int				getGame() const = 0;
	virtual std::string			getHighScore() const = 0;
	virtual bool				getEnd() const = 0;
	virtual bool				getEat() const = 0;
	virtual void				move(int) = 0;
};

#endif
