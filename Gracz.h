#ifndef GRACZ_H
#define GRACZ_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Gracz
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    //fizyka
    sf::Vector2f predkosc;
    float max_predkosc;
    float min_predkosc;
    float przyspieszenie;
    float opor;
    float grawitacja;
    float max_predkosc_y;

    //rdzen
    void inicjacja_texture();
    void inicjacja_sprite();
    void incjacja_fizyka();

public:
    Gracz();
    virtual ~Gracz();

    int skoki=0;

    //metody dostepu
    const sf::FloatRect granice_obiektu() const;

    //modyfikatory
    void ustaw_pozycje(const float x, const float y);
    void reset_predkosci_y();
    void reset_predkosci_x();

    //funkcje
    void ruch(const float dir_x, const float dir_y);
    void update_fizyka();
    void update_ruch();
    void update();
    void render(sf::RenderTarget& target);
};

#endif // GRACZ_H
