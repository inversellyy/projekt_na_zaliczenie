#ifndef PLATFORMY_H
#define PLATFORMY_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Platformy
{
private:
    sf::RectangleShape prostokat;

public:
    Platformy(sf::Vector2f wymiary, const float x, const float y);
    ~Platformy();

    const sf::FloatRect granice_obiektu() const;

    //funkcje
    void update();
    void render(sf::RenderTarget& target);
};

#endif // PLATFORMY_H
