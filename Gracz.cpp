#include "Gracz.h"

//rdzen
void Gracz::inicjacja_texture() {
    if(!this->texture.loadFromFile("Texture/tost.png")) {
        std::cout<<"Nie mozna zaladowac tekstury gracza!"<< "\n";
    }
}

void Gracz::inicjacja_sprite() {
    this->sprite.setTexture(this->texture);
}

void Gracz::incjacja_fizyka() {
    this->max_predkosc=7.f;
    this->min_predkosc=1.f;
    this->przyspieszenie=2.f;
    this->opor=0.92f;
    this->grawitacja=3.f;
    this->max_predkosc_y=20.f;
}

//konstruktor, destruktor
Gracz::Gracz() {
    this->ustaw_pozycje(10,500);
    this->inicjacja_texture();
    this->inicjacja_sprite();
    this->incjacja_fizyka();
}

Gracz::~Gracz() {

}


const sf::FloatRect Gracz::granice_obiektu() const {
    return this->sprite.getGlobalBounds();
}

//modyfikatory
void Gracz::ustaw_pozycje(const float x, const float y) {
    this->sprite.setPosition(x,y);
}

void Gracz::reset_predkosci_y() {
    this->predkosc.y=0.f;
}

void Gracz::reset_predkosci_x() {
    this->predkosc.x=0.f;
}

//funkcje
void Gracz::ruch(const float dir_x, const float dir_y) {
    //przyspieszenie
    this->predkosc.x += dir_x * this->przyspieszenie;
    this->predkosc.y += dir_y * this->przyspieszenie;

    //granica przyspieszenia
    if(std::abs(this->predkosc.x) > this->max_predkosc) {
        this->predkosc.x = this->max_predkosc * ((this->predkosc.x<0.f)? -1.f : 1.f);
    }
}

void Gracz::update_fizyka() {
    //grawitacja
    this->predkosc.y += 1.0 * this->grawitacja;
    if(std::abs(this->predkosc.y) > this->max_predkosc_y) {
        this->predkosc.y = this->max_predkosc_y * ((this->predkosc.y < 0.f)? -1.f : 1.f);
    }

    //opor
    this->predkosc *= this->opor;

    //granica oporu
    if(std::abs(this->predkosc.x) < this->min_predkosc) {
        this->predkosc.x=0.f;
    }
    if(std::abs(this->predkosc.y) < this->min_predkosc) {
        this->predkosc.y=0.f;
    }

    this->sprite.move(this->predkosc);
}

void Gracz::update_ruch() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && this->skoki<12) {
            //skok
            this->ruch(0.f,-10.f);
            skoki+=1;
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            //lewo
            this->ruch(-5.f,0.f);
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            //prawo
            this->ruch(5.f,0.f);
        }
}

void Gracz::update() {
    this->update_ruch();
    this->update_fizyka();
}

void Gracz::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}
