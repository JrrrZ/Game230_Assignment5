#include "Box.h"

using namespace sf;
using namespace gm;

Box::Box(const Vector2f& position, const Vector2f& size) : GameObject(position, size), direction(MovementDirection::None), colliderUp(Vector2f(getPosition().x, getPosition().y - 1), Vector2f(size.x - 1, 1)), colliderDown(Vector2f(getPosition().x, getPosition().y + 100), Vector2f(size.x -1, 1)) {
	body.setPosition(position);
	body.setSize(size);
}

void Box::update(sf::RenderWindow& window, float deltaTime){
	move(Vector2f(0, PlayerMovementSpeedPerSecond * direction * deltaTime));
	
	if (getPosition().y <= 0) {
		setPosition(Vector2f(0, 0));
	}
	else if (getPosition().y >= 540) {
		setPosition(Vector2f(0, 540));
	}
}

void Box::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Box::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
	colliderUp.left = position.x;
	colliderUp.top = position.y - 1;
	colliderDown.left = position.x;
	colliderDown.top = position.y + 100;
}

void Box::move(const Vector2f& velocity) {
	//if (getPosition().y >= 0 && getPosition().y <= 540) {
		GameObject::move(velocity);
		// Don't forget to update the Box's shape position to match the new position
		body.setPosition(position);
	//}
}

void Box::setMovmentDirection(MovementDirection direction) {
	this->direction = direction;
}

MovementDirection Box::getMovementDirection() const {
	return direction;
}


const Color& Box::getFillColor() const {
	return body.getFillColor();
}

void Box::setFillColor(const Color& color) {
	body.setFillColor(color);
}

// Returns a constant reference to the float rect used in collision detection
const FloatRect& Box::getColliderUp() const {
	return colliderUp;
}

// Returns a constant reference to the float rect used in collision detection
const FloatRect& Box::getColliderDown() const {
	return colliderDown;
}

// Checks to see if the float rect collider contains a specified point
//bool Box::collide(const Vector2f& point) const {
//	return collider.contains(point);
//}

// Checks to see if the float rect collider intersects another float rect
bool Box::collideUp(const FloatRect& rect) const {
	return colliderUp.intersects(rect);
}
bool Box::collideDown(const FloatRect& rect) const {
	return colliderDown.intersects(rect);
}

