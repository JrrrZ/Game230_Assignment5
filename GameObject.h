#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

// Use our gm namespace for all our defined classes
namespace gm {
	// Our abstract GameObject class that defines the interface for all objects that appear in our games
	class GameObject
	{
	// Protected accessibility allows direct access for deriving classes
	protected:
		// All GameObjects should have a position
		sf::Vector2f position;
		sf::FloatRect collider;
	public:
		// Default constructor
		GameObject();

		// Overloaded constructor that takes a position
		GameObject(const sf::Vector2f& position, const sf::Vector2f& size);

		// Our update interface, NOTE it is a pure virtual function
		virtual void update(sf::RenderWindow& window, float deltaTime) = 0;

		// Our render interface, NOTE it is a pure virtual function
		virtual void render(sf::RenderWindow& window, float deltaTime) = 0;

		// Our position getter, NOTE the const reference return and marking the method itself const
		virtual const sf::Vector2f& getPosition() const;

		// Our position setter, NOTE the pass by const reference
		virtual void setPosition(const sf::Vector2f& position);

		// Moves our game object relative to its current position
		virtual void move(const sf::Vector2f& velocity);

		// Our collider getter
		virtual const sf::FloatRect& getCollider() const;

		// Collision detection code
		virtual bool collide(const sf::Vector2f& point) const;

		virtual bool collide(const sf::FloatRect& rect) const;
	};
}

#endif