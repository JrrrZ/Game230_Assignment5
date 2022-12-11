#include "UI.h"
#include <iostream>

using namespace sf;
using namespace gm;

UI::UI(int scoreNum, Vector2f position) {
    score = scoreNum;
    //std::cout << score << std::endl;
    text.setPosition(position);
    if (!font.loadFromFile("Nasa21-l23X.ttf")) {
  
    }
    text.setFont(font);
    text.setString("Score " + std::to_string(score));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

}

int UI::GetScore() const
{
    return score;
}

void UI::setPosition(const Vector2f& position) {
    text.setPosition(position);
}

void UI::update(sf::RenderWindow& window) {
    text.setString("Score " + std::to_string(score));
}
 


void UI::render(sf::RenderWindow& window) {
    window.draw(text);
}

void UI::AddScore() {
    score++;
}

void UI::Player1Win() {
    text.setString("Player1 wins!");
    text.setPosition(300, 380);
}

void UI::Player2Win() {
    text.setString("Player2 wins!");
    text.setPosition(300, 380);
}

void UI::setScore(int scoreNum) {
    score = scoreNum;
}

UI::~UI() {

}