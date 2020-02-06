#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	//Moving circle vars
	sf::CircleShape circle;

	sf::Font font;
	sf::Text velocity_txt;

	// Circle speeds
	float speed_x;
	float speed_y;
	float dt_speed_x, dt_speed_y;

};