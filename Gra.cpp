#include "Gra.h"

//rdzen
void Gra::inicjacja_okna() {
    this->okno.create(sf::VideoMode(1700,900), "TOAST", sf::Style::Titlebar | sf::Style::Close);
    this->okno.setFramerateLimit(50);
}

void Gra::inicjacja_platformy() {
    this->platformy.push_back(Platformy(sf::Vector2f (100,50),460,610));
    this->platformy.push_back(Platformy(sf::Vector2f (300,50),120,470));
    this->platformy.push_back(Platformy(sf::Vector2f (150,50),220,260));
    this->platformy.push_back(Platformy(sf::Vector2f (350,50),400,150));
    this->platformy.push_back(Platformy(sf::Vector2f (500,50),865,450));
    this->platformy.push_back(Platformy(sf::Vector2f (200,50),1280,600));
}

void Gra::inicjacja_gracz() {
    this->gracz = new Gracz();
}

void Gra::inicjacja_wrogowie() {
    this->wrog = new Wrogowie();
}

void Gra::inicjacja_czcionki() {
    if(!this->font.loadFromFile("Font/JoeJack.ttf")){
        std::cout<<"Nie udalo sie zaladowac czcionki"<<"\n";
    }

    if(!this->font2.loadFromFile("Font/uwch.ttf")){
        std::cout<<"Nie udalo sie zaladowac czcionki"<<"\n";
    }
}

void Gra::inicjacja_tekstu() {
    this->tytul.setFont(this->font);
    this->tytul.setCharacterSize(80);
    this->tytul.setFillColor(sf::Color(209,109,38));
    this->tytul.setOutlineColor(sf::Color::Black);
    this->tytul.setOutlineThickness(7);
    this->tytul.setPosition(this->okno.getSize().x/2.f - 200,
                            this->okno.getSize().y/2.f - 200);
    this->tytul.setString("TOAST");

    this->instrukcja.setFont(this->font2);
    this->instrukcja.setCharacterSize(30);
    this->instrukcja.setFillColor(sf::Color(209,109,38));
    this->instrukcja.setOutlineColor(sf::Color::Black);
    this->instrukcja.setOutlineThickness(3);
    this->instrukcja.setPosition(this->okno.getSize().x/2.f - 600,
                                 this->okno.getSize().y/2.f);
    string << "pomoz tostowi uciec przed niebezpieczenstwem i dostac sie do tostera. " << '\n' <<
              "poruszaj sie klawiszami WAD. " << '\n' <<
              "uwazaj na noz, kuchenke i zlew. spotkanie z nimi zle sie zakonczy. " <<'\n' <<
              "wcisnij spacje aby zamknac instrukcje.";
    this->instrukcja.setString(string.str());

    this->zakonczenie.setFont(this->font);
    this->zakonczenie.setCharacterSize(70);
    this->zakonczenie.setFillColor(sf::Color(209,109,38));
    this->zakonczenie.setOutlineColor(sf::Color::Black);
    this->zakonczenie.setOutlineThickness(7);
    this->zakonczenie.setPosition(this->okno.getSize().x/2.f - 220,
                                  this->okno.getSize().y/2.f -100);
    this->zakonczenie.setString("the end");

    this->podziekowania.setFont(this->font2);
    this->podziekowania.setCharacterSize(40);
    this->podziekowania.setFillColor(sf::Color(209,109,38));
    this->podziekowania.setOutlineColor(sf::Color::Black);
    this->podziekowania.setOutlineThickness(4);
    this->podziekowania.setPosition(this->okno.getSize().x/2.f - 550,
                                  this->okno.getSize().y/2.f + 50);
    string2 << "special thanks to aga for the idea and textures." << '\n' << "wcisnij enter aby zagrac jeszcze raz.";
    this->podziekowania.setString(string2.str());
}

//konstruktor, destruktor
Gra::Gra(){
    this->inicjacja_okna();
    if(!texture.loadFromFile("Texture/tlo.png")) {
        std::cout<<"Nie mozna zaladowac tekstury tla!"<< "\n";
    }
    tlo.setTexture(texture);
    this->inicjacja_platformy();
    this->inicjacja_gracz();
    this->inicjacja_wrogowie();
    this->inicjacja_czcionki();
    this->inicjacja_tekstu();
}

Gra::~Gra(){
    delete this->gracz;
    delete this->wrog;
}

//funkcje
void Gra::update_platformy() {

}

void Gra::update_gracz() {
    this->gracz->update();
}

void Gra::update_wrogowie() {
    this->wrog->update();
}

void Gra::update_kolizja() {
    //kolizja z bokami ekranu
    if(this->gracz->granice_obiektu().left <= 0.f) {
        this->gracz->reset_predkosci_x();
        this->gracz->ustaw_pozycje(0.f, this->gracz->granice_obiektu().top);
    }

    if(this->gracz->granice_obiektu().left + this->gracz->granice_obiektu().width >= this->okno.getSize().x ) {
        this->gracz->reset_predkosci_x();
        this->gracz->ustaw_pozycje(this->okno.getSize().x - this->gracz->granice_obiektu().width, this->gracz->granice_obiektu().top);
    }

    //kolizcja z "ziemia"
    if(this->gracz->granice_obiektu().top + this->gracz->granice_obiektu().height > 775 && (this->gracz->granice_obiektu().left >1430 || this->gracz->granice_obiektu().left <680)) {
        this->gracz->reset_predkosci_y();
        this->gracz->ustaw_pozycje(this->gracz->granice_obiektu().left,
                                   775 - this->gracz->granice_obiektu().height);
    }

    //kolizja z "przepascia"
    if(this->gracz->granice_obiektu().top + this->gracz->granice_obiektu().height > 810 ) {
        this->gracz->ustaw_pozycje(10,700);
    }

    //kolizja z platformami
    for (auto&& i : this->platformy) {
        if(this->gracz->granice_obiektu().intersects(i.granice_obiektu()) && (this->gracz->granice_obiektu().top + 0.8 * this->gracz->granice_obiektu().height) < i.granice_obiektu().top) {
            this->gracz->reset_predkosci_y();
            this->gracz->ustaw_pozycje(this->gracz->granice_obiektu().left,
                                       i.granice_obiektu().top - this->gracz->granice_obiektu().height);
        }
    }

    //kolizja z wrogiem
    if(this->gracz->granice_obiektu().intersects(this->wrog->granice_obiektu())) {
        this->gracz->ustaw_pozycje(10,500);
    }

    //kolizja z tosterem
    if(this->gracz->granice_obiektu().top + this->gracz->granice_obiektu().height > 770 && this->gracz->granice_obiektu().left > 1570 ) {
        this->gracz->reset_predkosci_x();
        this->gracz->reset_predkosci_y();
        this->gracz->ustaw_pozycje(10,500);
        koniec_gry=true;
    }

}

void Gra::update() {
    //polling window events
    while(this->okno.pollEvent(this->event)) {
        if(this->event.type == sf::Event::Closed) {
            this->okno.close();
        } else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape) {
            this->okno.close();
        } else if(this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::Space) {
            poczatek_gry=false;
        } else if(this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::W) {
            this->gracz->skoki=0;
        } else if(this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::Enter) {
            try_again=true;
        }
    }
    this->update_platformy();
    this->update_gracz();
    this->update_wrogowie();
    this->update_kolizja();
}

void Gra::render_platformy() {
    for(auto&& i : this->platformy){
        i.render(this->okno);
    }
}

void Gra::render_gracz() {
    this->gracz->render(this->okno);
}

void Gra::render_wrogowie() {
    this->wrog->render(this->okno);
}

void Gra::render() {
    this->okno.clear();

    //gra
    this->okno.draw(tlo);
    this->render_platformy();
    this->render_gracz();
    this->render_wrogowie();

    //instrukcje, napisy koncowe
    if(poczatek_gry==true) {
        okno.draw(this->tytul);
        okno.draw(this->instrukcja);
    }

    if(koniec_gry==true && try_again==false) {
        okno.draw(this->zakonczenie);
        okno.draw(this->podziekowania);
    }

    this->okno.display();
}
