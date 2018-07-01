// EPITECH PROJECT, 2018
// arcade
// File description:
// graphic
//

#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <unistd.h>
#include "SMenu.hpp"

void	SMenu::setMap(const std::vector<std::string> map)
{
	_map = map;
}

void	SMenu::print_info2()
{
	sf::Text				info6;
	sf::Text				info7;
	sf::Text				info8;
	sf::Text				info9;
	sf::Text				info10;
	sf::Text				info11;
	sf::Font				font;

	font.loadFromFile("ressources/EB.ttf");
	info6.setFont(font);
	info6.setString("AVAILABLE GAMES");
	info6.setCharacterSize(24);
	info6.setPosition(10, 10);
	info6.setColor(sf::Color::White);
	info7.setFont(font);
	info7.setString("PACMAN");
	info7.setCharacterSize(24);
	info7.setPosition(10, 60);
	info7.setColor(sf::Color::White);
	info8.setFont(font);
	info8.setString("NIBBLER");
	info8.setCharacterSize(24);
	info8.setPosition(10, 110);
	info8.setColor(sf::Color::White);
	info9.setFont(font);
	info9.setString("AVAILABLE LIB");
	info9.setCharacterSize(24);
	info9.setPosition(1700, 10);
	info9.setColor(sf::Color::White);
	info10.setFont(font);
	info10.setString("NCURSES");
	info10.setCharacterSize(24);
	info10.setPosition(1700, 60);
	info10.setColor(sf::Color::White);
	info11.setFont(font);
	info11.setString("SFML");
	info11.setCharacterSize(24);
	info11.setPosition(1700, 110);
	info11.setColor(sf::Color::White);
	_win->draw(info6);
	_win->draw(info7);
	_win->draw(info8);
	_win->draw(info9);
	_win->draw(info10);
	_win->draw(info11);
}

void	SMenu::print_info()
{
	sf::Text				title;
	sf::Font				font;
	sf::Text				sc;
	sf::Text				score;
	sf::Text				HighScore;
	sf::Text				hS;
	sf::Text				info;
	sf::Text				info2;
	sf::Text				info3;
	sf::Text				info4;
	sf::Text				info5;
	sf::Text				info12;

	font.loadFromFile("ressources/EB.ttf");
	info4.setFont(font);
	info4.setString("PRESS S TO MUTE");
	info4.setCharacterSize(24);
	info4.setColor(sf::Color::Blue);
	info4.setPosition(1450, 650);
	info4.setFont(font);
	info5.setFont(font);
	info5.setString("PRESS N OR B TO CHANGE LIB");
	info5.setCharacterSize(24);
	info5.setColor(sf::Color(222, 103, 57));
	info5.setPosition(1450, 700);
	info12.setFont(font);
	info12.setString("PRESS O OR P TO CHANGE GAME");
	info12.setCharacterSize(24);
	info12.setColor(sf::Color(156, 180, 144));
	info12.setPosition(1450, 750);
	info.setFont(font);
	info.setString("PRESS R TO RESTART");
	info2.setFont(font);
	info2.setString("PRESS M FOR THE MENU");
	info3.setFont(font);
	info3.setString("PRESS ESCAPE TO EXIT");
	title.setFont(font);
	if (_g == 0)
		title.setString("PACMAN");
	else
		title.setString("NIBBLER");
	info.setCharacterSize(24);
	info2.setCharacterSize(24);
	info3.setCharacterSize(24);
	title.setCharacterSize(54);
	title.setColor(sf::Color::Blue);
	title.setStyle(sf::Text::Bold);
	title.setPosition(850, 100);
	sc.setFont(font);
	hS.setFont(font);
	HighScore.setFont(font);
	sc.setString("SCORE");
	hS.setString("HIGHSCORE");
	HighScore.setString(_highScore);
	sc.setCharacterSize(30);
	hS.setCharacterSize(30);
	HighScore.setCharacterSize(30);
	info.setColor(sf::Color::Red);
	info2.setColor(sf::Color::Yellow);
	info3.setColor(sf::Color::Green);
	sc.setColor(sf::Color(156, 180, 144));
	hS.setColor(sf::Color(222, 103, 57));
	HighScore.setColor(sf::Color(222, 103, 57));
	sc.setPosition(250, 600);
	hS.setPosition(250, 700);
	HighScore.setPosition(400, 700);
	score.setFont(font);
	score.setString(_score);
	score.setCharacterSize(30);
	score.setColor(sf::Color(156, 180, 144));
	score.setPosition(400, 600);
	info.setPosition(1450, 500);
	info2.setPosition(1450, 550);
	info3.setPosition(1450, 600);
	_win->draw(title);
	_win->draw(sc);
	_win->draw(score);
	_win->draw(hS);
	_win->draw(HighScore);
	_win->draw(info);
	_win->draw(info2);
	_win->draw(info3);
	_win->draw(info4);
	_win->draw(info5);
	_win->draw(info12);
	print_info2();
}

void	SMenu::drawMap(IGame *game)
{
	int					x, y = 250;
	
	print_info();
	for (auto i : _map) {
		x = 550;
		std::string tmp = i;

		for (auto a : tmp) {
			switch (a) {
			case '#':
				D_wall(x, y);
				break;
			case '*':
				D_fruit(x, y);
				break;
			case '{':
				D_pacR(x, y);
				break;
			case '}':
				D_pacL(x, y);
				break;
			case 'v':
				D_pacU(x, y);
				break;
			case 'n':
				D_pacD(x, y);
				break;
			case '6':
				if (game->getEat() == true)
					D_ghostE(x, y);
				else
					D_ghost(x, y);
				break;
			case '0':
				D_powerUps(x, y);
				break;
			case '>':
				D_nibblerR(x, y);
				break;
			case 'y':
				D_nibblerD(x, y);
				break;
			case '^':
				D_nibblerU(x, y);
				break;
			case '<':
				D_nibblerL(x, y);
				break;
			case 'o':
				D_nibblerB(x, y);
				break;
			case 'f':
				D_nibblerF(x, y);
			}
			x = x + 25;
		}
		y = y + 25;
	}
}

void    SMenu::addHighScore()
{
	std::ofstream	file;

	if (std::stoi(_highScore) < std::stoi(_score)) {
		if (_g == 0)
			file.open("ressources/HighScoreP");
		else
			file.open("ressources/HighScoreN");
		if (file)
			file << _score;
		_highScore = _score;
		file.close();
	}
}

int	SMenu::draw(IGame *game)
{
	sf::Music		music;

	_g = game->getGame();
	if (_g == 0) {
		music.openFromFile("ressources/pac.ogg");
		music.setLoop(true);
		music.play();
		music.setPlayingOffset(sf::seconds(8));
	}
	else {
		music.openFromFile("ressources/bambino.ogg");
		music.setLoop(true);
		music.play();
		music.setPlayingOffset(sf::seconds(7));
	}
	_score = std::to_string(game->getScore());
	_highScore = game->getHighScore();
	_win = new sf::RenderWindow(sf::VideoMode(1920, 1080), "ARCADE");
	setMap(game->getMap());
	while (_win->isOpen()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(120));
		sf::Event e;

		while (_win->pollEvent(e)) {
			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Up) {
					_dir = UP;
				}
				else if (e.key.code == sf::Keyboard::Down) {
					_dir = DOWN;
				}
				else if (e.key.code == sf::Keyboard::Right) {
					_dir = RIGHT;
				}
				else if (e.key.code == sf::Keyboard::Left) {
					_dir = LEFT;
				}
				else if (e.key.code == sf::Keyboard::Escape) {
					music.stop();
					_win->close();
					exit(0);
				}
				else if (e.key.code == sf::Keyboard::B) {
					music.stop();
					_win->close();
					return (CHANGE_LIB);
				}
				else if (e.key.code == sf::Keyboard::N) {
					music.stop();
					_win->close();
					return (CHANGE_LIB);
				}
				else if (e.key.code == sf::Keyboard::R) {
					music.stop();
					_win->close();
					return (RES_PAC);
				}
				else if (e.key.code == sf::Keyboard::M) {
					music.stop();
					_win->close();
					return (BACK_MENU);
				}
				else if (e.key.code == sf::Keyboard::O) {
					music.stop();
					_win->close();
					return (CHANGE_G);
				}
				else if (e.key.code == sf::Keyboard::P) {
					music.stop();
					_win->close();
					return (CHANGE_G);
				}
				else if (e.key.code == sf::Keyboard::S) {
					if (music.getStatus() == sf::SoundSource::Status::Playing)
						music.pause();
					else
						music.play();
				}
				break;
			}
			else if (e.type == sf::Event::Closed) {
				music.stop();
				_win->close();
				exit(0);
			}
		}
		game->move(_dir);
		_win->clear(sf::Color(122, 101, 160));
		_score = std::to_string(game->getScore());
		setMap(game->getMap());
		drawMap(game);
		_win->display();
		if (checkWin() == true && _g == 0) {
			addHighScore();
			music.stop();
			_win->close();
			return (win());
		}
		if (game->getEnd() == true) {
			addHighScore();
			music.stop();
			_win->close();
			return (gameOver());
		}
	}
	music.stop();
	return (0);
}
