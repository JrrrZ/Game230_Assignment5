#ifndef UI_H
#define UI_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

namespace gm {
    class UI
    {
    private:
        Text text;
        int score = 0;
        Font font;
        Text win;

    public:
        // Constructor
        UI(int scoreNum, Vector2f position);

        // Get the current score
        int GetScore() const;

        // Set the current score
        void AddScore();

        void setScore(int scoreNum);

        void setPosition(const sf::Vector2f& position);

        void update(sf::RenderWindow& window);

        void render(sf::RenderWindow& window);

        // Destructor
        ~UI();
        
        void Player1Win();

        void Player2Win();
    };
}

#endif