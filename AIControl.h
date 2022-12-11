#ifndef AI_CONTROL_H
#define AI_CONTRO_H

#include "GameObject.h"

namespace gm {
    // Box movement speed
    const int AIPlayerMovementSpeedPerSecond = 300;

    enum AIMovementDirection {
        AINone = 0,
        AILeft = -1,
        AIRight = 1
    };

    class AIControl :
        public GameObject
    {
    protected:
        sf::RectangleShape body;
        AIMovementDirection direction;

        sf::FloatRect colliderUp;
        sf::FloatRect colliderDown;

    public:
        AIControl(const sf::Vector2f& position, const sf::Vector2f& size);

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;

        // Move the box from its current position to a new one with a specified velocity
        virtual void move(const sf::Vector2f& velocity) override;

        virtual void setMovmentDirection(AIMovementDirection direction);

        virtual AIMovementDirection getMovementDirection() const;

        const sf::Color& getFillColor() const;

        void setFillColor(const sf::Color& color);

        // Our collider getter
        virtual const sf::FloatRect& getColliderUp() const;

        virtual const sf::FloatRect& getColliderDown() const;

        // Collision detection code
        virtual bool collideUp(const sf::FloatRect& rect) const;
        virtual bool collideDown(const sf::FloatRect& rect) const;
    };
}

#endif