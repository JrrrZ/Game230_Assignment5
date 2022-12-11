// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), box1(Vector2f(0, 320), Vector2f(20,100)), box2(Vector2f(620, 320), Vector2f(20, 100)), ball(Vector2f(310,320), Vector2f(20,20), ball.getVelocity().x, ball.getVelocity().y), score1(0, Vector2f(50, 50)), score2(0, Vector2f(500, 50)) , Win(0, Vector2f(300, 380)), SFX() {
	// Set our fps to 60
	window.setFramerateLimit(60);

}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

			// Handle keyboard input to move box 1
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Up) {
					if (box1.getPosition().y >= 0) {
						box1.setMovmentDirection(MovementDirection::Left);
					}
						if (box1.getPosition().y == 0) {
							box1.setMovmentDirection(MovementDirection::None);
						}
				}
				else if (event.key.code == Keyboard::Down) {

					box1.setMovmentDirection(MovementDirection::Right);
				}
			}

			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up && box1.getMovementDirection() == MovementDirection::Left) {
					box1.setMovmentDirection(MovementDirection::None);

				}
				if (event.key.code == Keyboard::Down && box1.getMovementDirection() == MovementDirection::Right) {
					box1.setMovmentDirection(MovementDirection::None);

				}
			}
		

		if (score1.GetScore() >= 5 || score2.GetScore() >= 5) {
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Space) {
					score1.setScore(0);
					score2.setScore(0);
					ball.rebirth();
				}
			}
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	// Update our boxes (i.e., move them based on the block's specified movement direction)
	box1.update(window, deltaTime);
	box2.update(window, deltaTime);
	ball.update(window, deltaTime);
	score1.update(window);
	score2.update(window);
	SFX.loadSound();
	ball.setFillColor(Color::White);
	// If the mouse has entered box 1 then color it green
	if (box1.collide(Vector2f(Mouse::getPosition(window)))) {
		box1.setFillColor(Color::Green);
	} else {
		box1.setFillColor(Color::White);
	}

	// If the mouse has entered box 2 then color it green
	if (box2.collide(Vector2f(Mouse::getPosition(window)))) {
		box2.setFillColor(Color::Green);
	}
	else {
		box2.setFillColor(Color::White);
	}


	// Ball reborn
	if (ball.getPosition().x <= 0 || ball.getPosition().x >= 620) {
		rebornTimer += deltaTime;
		//std::cout << ball.getPosition().x << ", " << ball.getPosition().y << std::endl;
		if (ball.getPosition().x <= 0) {
			score2Add = true;
		}
		else if (ball.getPosition().x >= 620) {
			score1Add = true;
		}
		if (rebornTimer >= 2) {
			//std::cout << "rebirth" << std::endl;
			ball.rebirth();
			if (gameStart == true) {
				if (score1Add == true) {
					score1.AddScore();
					score1Add = false;
				}
				else if (score2Add == true) {
					score2.AddScore();
					score2Add = false;
				}
			}
			rebornTimer = 0;
			gameStart = true;
		}
	}
	if (box1.collideUp(ball.getCollider()) || box2.collideUp(ball.getCollider()) || box1.collideDown(ball.getCollider()) || box2.collideDown(ball.getCollider())) {
		SFX.playSFX();
		ball.setUpWall(true);
		ball.BounceWall();
	}
	//
	else if (box1.collide(ball.getCollider())) {
		SFX.playSFX();
		ball.BounceWall();
	}
	else if (box2.collide(ball.getCollider())) {
		SFX.playSFX();
		ball.BounceWall();
	}
	


	// AI
	if (ball.getPosition().y >= 0 && ball.getPosition().y <= 620 && ball.getPosition().x >= 0 && ball.getPosition().x <= 620) {
		if (ball.getPosition().y < box2.getPosition().y && box2.getPosition().y >= 0) {
			box2.move(Vector2f(0, PlayerMovementSpeedPerSecond * -1 * deltaTime));
		}
		else if (ball.getPosition().y > box2.getPosition().y && box2.getPosition().y <= 540) {
			box2.move(Vector2f(0, PlayerMovementSpeedPerSecond * 1 * deltaTime));
		}
		//else if ()
	}

	// Score
	if (score1.GetScore() >= 5 || score2.GetScore() >= 5) {
		//Iswin = true;
		if (score1.GetScore() >= 5) {
			Win.Player1Win();
		}
		else if (score2.GetScore() >= 5) {
			Win.Player2Win();
		}
		ball.setVelocity(0,0);
	}
	else {
		//Iswin = false;
		//score1.setScore(0);
		//score2.setScore(0);
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our boxes
	box1.render(window, deltaTime);
	box2.render(window, deltaTime);
	ball.render(window, deltaTime);
	score1.render(window);
	score2.render(window);
	if (score1.GetScore() >= 5 || score2.GetScore() >= 5) {
		Win.render(window);
	}
	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}
