// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* Our Includes */
#include "Box.h"
#include "SquareBall.h"
#include "UI.h"
#include "SoundManager.h"
#include "AIControl.h"
// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	const int GameWidth = 640;
	const int GameHeight = 640;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// The game window
		sf::RenderWindow window;
		// For tracking/maintaining delta time
		sf::Clock clock;
		float deltaTime;
		// Our game objects
		Box box1;
		AIControl box2;
		SquareBall ball;
		UI score1;
		UI score2;
		UI Win;
		SoundManager SFX;
		Sound _sfx;
		int m_score = 0;
		int e_score = 0;
		float rebornTimer = 2;
		bool gameStart = false;
		bool score2Add = false;
		bool score1Add = false;
		bool Iswin = false;

	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		// Destructor
		~Game();
	};
}

#endif