#include "AIControl.h"

using namespace sf;
using namespace gm;

AIControl::AIControl(const Vector2f& position, const Vector2f& size) : GameObject(position, size), direction(AIMovementDirection::AINone), colliderUp(Vector2f(getPosition().x, getPosition().y - 1), Vector2f(size.x - 1, 1)), colliderDown(Vector2f(getPosition().x, getPosition().y + 100), Vector2f(size.x - 1, 1)) {
	body.setPosition(position);
	body.setSize(size);
}

void AIControl::update(sf::RenderWindow& window, float deltaTime) {
	move(Vector2f(0, AIPlayerMovementSpeedPerSecond * direction * deltaTime));
}

void AIControl::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void AIControl::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
	colliderUp.left = position.x;
	colliderUp.top = position.y - 1;
	colliderDown.left = position.x;
	colliderDown.top = position.y + 100;
}

void AIControl::move(const Vector2f& velocity) {
	//if (getPosition().y >= 0 && getPosition().y <= 540) {
	GameObject::move(velocity);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
	//}
}

void AIControl::setMovmentDirection(AIMovementDirection direction) {
	this->direction = direction;
}

AIMovementDirection AIControl::getMovementDirection() const {
	return direction;
}


const Color& AIControl::getFillColor() const {
	return body.getFillColor();
}

void AIControl::setFillColor(const Color& color) {
	body.setFillColor(color);
}

// Returns a constant reference to the float rect used in collision detection
const FloatRect& AIControl::getColliderUp() const {
	return colliderUp;
}

// Returns a constant reference to the float rect used in collision detection
const FloatRect& AIControl::getColliderDown() const {
	return colliderDown;
}

// Checks to see if the float rect collider contains a specified point
//bool Box::collide(const Vector2f& point) const {
//	return collider.contains(point);
//}

// Checks to see if the float rect collider intersects another float rect
bool AIControl::collideUp(const FloatRect& rect) const {
	return colliderUp.intersects(rect);
}
bool AIControl::collideDown(const FloatRect& rect) const {
	return colliderDown.intersects(rect);
}