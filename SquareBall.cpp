#include "SquareBall.h"
#include "Box.h"
#include <math.h>
#include <iostream>

using namespace sf;
using namespace gm;

SquareBall::SquareBall(const Vector2f& position, const Vector2f& bSize, float vX, float vY) : GameObject(position, bSize) {
	bBody.setPosition(position);
	bBody.setSize(bSize);
	bvX = vX;
	bvY = vY;
}

void SquareBall::update(sf::RenderWindow& window, float deltaTime) {
	move(Vector2f(bvX, bvY));

	if (getPosition().y <= 0) {
		isWall = true;
		BounceWall();
		if (getPosition().y <= 50)
			bBody.setFillColor(Color::Green);
	}
	else if (getPosition().y >= 620) {
		isWall = true;
		BounceWall();
		setFillColor(Color::Green);
	}
	//else if (getPosition().x >= 620) {
	//	downWall = true;
	//	BounceWall();
	//	setFillColor(Color::Green);
	//}
	//else if (getPosition().x <= 0) {
	//	downWall = true;
	//	BounceWall();
	//	setFillColor(Color::Green);
	//}
}

void SquareBall::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(bBody);
}

void SquareBall::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	// Don't forget to update the Box's shape position to match the new position
	bBody.setPosition(position);
}

void SquareBall::move(const Vector2f& velocity) {
	GameObject::move(velocity * speed);
	// Don't forget to update the Box's shape position to match the new position
	bBody.setPosition(position);
}

const Color& SquareBall::getFillColor() const {
	return bBody.getFillColor();
}

void SquareBall::setFillColor(const Color& color) {
	bBody.setFillColor(color);
}

void SquareBall::setUpWall(bool value) {
	isWall = value;
}

Vector2f SquareBall::getVelocity() {
	return Vector2f(bvX, bvY);
}

void SquareBall::setVelocity(float vX, float vY) {
	bvX = vX;
	bvY = vY;
}

void SquareBall::rebirth() {
	speed = 3;
	setPosition(Vector2f(310, 320));
	float newVx = random(-100, 100);
	float newVy = random(-50, 50);
	float newSpeed = sqrtf(newVx * newVx + newVy * newVy);
	bvX = newVx / newSpeed;
	bvY = newVy / newSpeed;
	if (bvX == 0 && bvY == 0 || bvX == 0 && bvY == 1 || bvX == 0 && bvY == -1) {
		rebirth();
	}
}

void SquareBall::BounceWall () {
	// Walls
	if (isWall) {
		Vector2f N(1, 0);
		Vector2f bWall = 2 * (N.x   * bvX + N.y * bvY) * N - Vector2f(bvX, bvY);
		//std::cout << bvX << " " << bvY << " " << bWall.x << " " << bWall.y << std::endl;
		setVelocity(bWall.x, bWall.y);
		isWall = false;
	}
	// Paddles
	else {
		Vector2f N(0, 1);
		Vector2f bWall = 2 * (N.x * bvX + N.y * bvY) * N - Vector2f(bvX, bvY);
		//Vector2f bWall = (Vector2f(2 * N.x * bvX * N.x, 2 * N.y * bvY * N.y)) - Vector2f(bvX, bvY);
		//std::cout << bvX << " " << bvY << " " << bWall.x << " " << bWall.y << std::endl;
		setVelocity(bWall.x, bWall.y);
		speed++;
	}
}
int SquareBall::random(int minNum, int maxNum) {
	return minNum + rand() % (maxNum - minNum + 1);
}
