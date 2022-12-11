#ifndef SQUAREBALL_H
#define SQUAREBALL

#include "GameObject.h"

namespace gm {


    class SquareBall :
        public GameObject
    {
    protected:
        sf::RectangleShape bBody;
        float bvX;
        float bvY;
        float speed = 10;
 
        bool isWall = false;

    public:
        SquareBall(const sf::Vector2f& position, const sf::Vector2f& bSize, float vX, float vY);

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;

        // Move the ball from its current position to a new one with a specified velocity
        virtual void move(const sf::Vector2f& velocity) override;

        sf::Vector2f getVelocity();

        void setVelocity(float vX, float vY);

        const sf::Color& getFillColor() const;

        void setFillColor(const sf::Color& color);

        void setUpWall(bool value);

        void BounceWall();

        void rebirth();

        int random(int minNum, int maxNum);
    };
}

#endif


