#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	//Moving circle defined
	circle.setRadius(15);
	circle.setPosition(100, 100);
	//circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	speed_x = 10.f;
	speed_y = 10.f;

	//Text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}
	velocity_txt.setFont(font);
	velocity_txt.setString("Velocity (x,y)");
	velocity_txt.setCharacterSize(24);
	velocity_txt.setFillColor(sf::Color::Red);
	velocity_txt.setStyle(sf::Text::Bold | sf::Text::Underlined);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		speed_y -= 10.1f;
		input->setKeyUp(sf::Keyboard::Up);
	}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		speed_y += 10.1f;
		input->setKeyUp(sf::Keyboard::Down);
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		speed_x -= 10.1f;
		input->setKeyUp(sf::Keyboard::Left);
	}
	else if (input->isKeyDown(sf::Keyboard::Right))
	{
		speed_x += 10.1f;
		input->setKeyUp(sf::Keyboard::Right);
	}
}

// Update game objects
void Level::update(float dt)
{
	//Get size of window
	sf::Vector2u window_size = window->getSize();
	//Get position of circle
	sf::Vector2f circle_position = circle.getPosition();

	// Control x position
	if (circle_position.x > window_size.x - circle.getRadius() * 2)
	{
		//Set speed
		circle_position.x = window_size.x - circle.getRadius() * 2;
		speed_x = -speed_x;
		std::cout << "Bouncing right\n";
	}
	else if (circle_position.x < 0 )
	{
		//Set speed
		circle_position.x = 0;
		speed_x = -speed_x;
		std::cout << "Bouncing left\n";
	}

	// Control y position
	if (circle_position.y > window_size.y - circle.getRadius() * 2)
	{
		//Set speed
		circle_position.y = window_size.y - circle.getRadius() * 2;
		speed_y = -speed_y;
		std::cout << "Bouncing bottom\n";
	}	
	else if (circle_position.y < 0)
	{
		//Set speed
		circle_position.y = 0;
		speed_y = -speed_y;
		std::cout << "Bouncing top\n";
	}

	//Calculate dt speeds
	dt_speed_x = speed_x * dt;
	dt_speed_y = speed_y * dt;

	// Update/move circle
	circle.move(dt_speed_x, dt_speed_y); //Speed with delta

	//Update speed_txt
	velocity_txt.setString("Speed (" + std::to_string(speed_x) + "," + std::to_string(speed_y) + ")");

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(velocity_txt);

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