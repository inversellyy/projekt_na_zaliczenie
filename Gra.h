#ifndef GRA_H
#define GRA_H

#include "Gracz.h"
#include "Wrogowie.h"
#include "Platformy.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Gra
{
private:
    sf::RenderWindow okno;
    sf::Event event;
    bool koniec_gry=false;
    bool poczatek_gry=true;
    bool try_again=false;

    //tlo
    sf::Sprite tlo;
    sf::Texture texture;

    //swiat i postacie
    Gracz* gracz;
    Wrogowie* wrog;
    std::vector<Platformy> platformy;

    //tekst
    sf::Font font, font2;
    sf::Text tytul, instrukcja, zakonczenie, podziekowania;
    std::stringstream string, string2;

    //rdzen
    void inicjacja_okna();
    void inicjacja_platformy();
    void inicjacja_gracz();
    void inicjacja_wrogowie();
    void inicjacja_czcionki();
    void inicjacja_tekstu();

public:
    Gra();
    virtual ~Gra();

    //funkcje
    void update_platformy();
    void update_gracz();
    void update_wrogowie();
    void update_kolizja();
    void update();

    void render_platformy();
    void render_gracz();
    void render_wrogowie();
    void render();

    const sf::RenderWindow& getWindow() const{
        return this->okno;
    }
};

#endif // GRA_H
