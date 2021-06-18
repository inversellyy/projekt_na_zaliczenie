#include "Wrogowie.h"

//rdzen
void Wrogowie::inicjacja_texture() {
    if(!this->texture.loadFromFile("Texture/knife.png")) {
        std::cout<<"Nie mozna zaladowac tekstury wroga!"<< "\n";
    }
}

void Wrogowie::inicjacja_sprite() {
    this->sprite.setTexture(this->texture);
}

void Wrogowie::ustaw_pozycje(const float x, const float y) {
    this->sprite.setPosition(x,y);
}

//kontruktor, destruktor
Wrogowie::Wrogowie() {
    this->ustaw_pozycje(700,270);
    this->inicjacja_texture();
    this->inicjacja_sprite();
}

Wrogowie::~Wrogowie() {

}


const sf::FloatRect Wrogowie::granice_obiektu() const {
    return this->sprite.getGlobalBounds();
}


//funkcje
void Wrogowie::ruch(const float dir_x, const float dir_y) {
    this->sprite.move(dir_x, dir_y);
}

void Wrogowie::update_ruch() {
    if(1) {
        if(this->granice_obiektu().top == 271) {
            this->ruch(-3.f,0.f);
        } else if(this->granice_obiektu().top == 270) {
            this->ruch(3.f,0.f);
    }

    if(this->granice_obiektu().left < 845) {
            this->ustaw_pozycje(845,270);
        } else if(this->granice_obiektu().left > 1340) {
            this->ustaw_pozycje(1340,271);
        }
    }
}

void Wrogowie::update() {
    this->update_ruch();
}

void Wrogowie::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}
