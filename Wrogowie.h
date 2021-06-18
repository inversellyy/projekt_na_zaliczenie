#ifndef WROGOWIE_H
#define WROGOWIE_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Wrogowie
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    //rdzen
    void inicjacja_texture();
    void inicjacja_sprite();
    void ustaw_pozycje(const float x, const float y);
public:
    Wrogowie();
    virtual ~Wrogowie();

    const sf::FloatRect granice_obiektu() const;

    //funkcje
    void ruch(const float dir_x, const float dir_y);
    void update_ruch();
    void update();
    void render(sf::RenderTarget& target);
};

#endif // WROGOWIE_H
