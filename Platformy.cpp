#include "Platformy.h"

//konstruktor, destruktor
Platformy::Platformy(sf::Vector2f wymiary, const float x, const float y)
{
    this->prostokat.setSize(wymiary);
    this->prostokat.setPosition(sf::Vector2f(x,y));
    this->prostokat.setFillColor(sf::Color(84,36,57));
    this->prostokat.setOutlineColor(sf::Color::Black);
    this->prostokat.setOutlineThickness(10);
}

Platformy::~Platformy() {

}

const sf::FloatRect Platformy::granice_obiektu() const {
    return this->prostokat.getGlobalBounds();
}

//funkcje
void Platformy::update() {

}

void Platformy::render(sf::RenderTarget &target) {
    target.draw(this->prostokat);
}
