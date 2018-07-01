//
// EPITECH PROJECT, 2018
// arcade
// File description:
// game over sfml
//

#include "SMenu.hpp"

bool	SMenu::checkWin()
{
	std::vector<std::string>::iterator	it = _map.begin();

	for (auto i : _map) {
		std::string tmp = i;

		for (auto a : tmp) {
		        if (a == '*')
				return (false);
		}
	}
	return (true);
}

int	SMenu::win()
{
	sf::Font        font;
	sf::Music	music;

	music.openFromFile("ressources/SS.ogg");
	music.setLoop(true);
	music.play();
	music.setPlayingOffset(sf::seconds(23));
	font.loadFromFile("ressources/EB.ttf");
	_win = new sf::RenderWindow(sf::VideoMode(1920, 1080), "WIN");
	while (_win->isOpen()) {
		sf::Event       e;
		sf::Text        gO;
		sf::Text	info;
		sf::Text	info2;
		sf::Text	info3;
		sf::Text	info4;
		sf::Text	HighScore;
		sf::Text	hS;
		sf::Text	sc;
		sf::Text	score;

		while (_win->pollEvent(e)) {
			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::R) {
					music.stop();
					_win->close();
					return (RES_PAC);
				}
				else if (e.key.code == sf::Keyboard::Escape) {
					music.stop();
					_win->close();
					exit (0);
				}
				else if (e.key.code == sf::Keyboard::M) {
					music.stop();
					_win->close();
					return (-1);
				}
				else if (e.key.code == sf::Keyboard::S) {
					if (music.getStatus() == sf::SoundSource::Status::Playing)
						music.pause();
					else
						music.play();
				}
				
			}
			if (e.type == sf::Event::Closed) {
				music.stop();
				_win->close();
				return (-1);
			}
		}
		_win->clear(sf::Color(122, 101, 160));
		info4.setFont(font);
		info4.setString("PRESS S TO MUTE");
		info4.setCharacterSize(40);
		info4.setColor(sf::Color(222, 103, 57));
		info4.setPosition(750, 650);
		gO.setFont(font);
		info.setFont(font);
		info.setString("PRESS R TO RESTART");
		info2.setFont(font);
		info2.setString("PRESS M FOR THE MENU");
		info3.setFont(font);
		info3.setString("PRESS ESCAPE TO EXIT");
		gO.setString("YOU WIN");
		info.setCharacterSize(40);
		info2.setCharacterSize(40);
		info3.setCharacterSize(40);
		gO.setCharacterSize(94);
		info.setColor(sf::Color::Red);
		info2.setColor(sf::Color::Yellow);
		info3.setColor(sf::Color::Green);
		gO.setColor(sf::Color::Blue);
		hS.setColor(sf::Color::Blue);
		HighScore.setColor(sf::Color::Blue);
		sc.setColor(sf::Color::Blue);
		score.setColor(sf::Color::Blue);
		gO.setStyle(sf::Text::Bold);
		info.setPosition(750, 500);
		info2.setPosition(750, 550);
		info3.setPosition(750, 600);
		hS.setFont(font);
		sc.setFont(font);
		HighScore.setFont(font);
		score.setFont(font);
		hS.setString("HIGHSCORE");
		sc.setString("SCORE");
		HighScore.setString(_highScore);
		score.setString(_score);
		sc.setCharacterSize(40);
		score.setCharacterSize(40);
		hS.setCharacterSize(40);
		HighScore.setCharacterSize(40);
		hS.setColor(sf::Color(222, 103, 57));
		HighScore.setColor(sf::Color(222, 103, 57));
		sc.setColor(sf::Color(156, 180, 144));
		score.setColor(sf::Color(156, 180, 144));
		sc.setPosition(200, 500);
		score.setPosition(400, 500);
		hS.setPosition(200, 600);
		HighScore.setPosition(400, 600);
		gO.setPosition(750, 200);
		_win->draw(gO);
		_win->draw(info);
		_win->draw(info2);
		_win->draw(info3);
		_win->draw(info4);
		_win->draw(sc);
		_win->draw(score);
		_win->draw(hS);
		_win->draw(HighScore);
		_win->display();
	}
	return (-1);
}

