#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	//Moving circle defined
	circle.setRadius(15);
	circle.setPosition(100, 100);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	speed = 10.f;

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	// Update/move circle
	circle.move(speed * dt, 0); //Speed with delta
	//circle.move(speed, 0); //Speed without delta
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}