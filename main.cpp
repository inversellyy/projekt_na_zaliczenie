#include "Gra.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    Gra gra;

    //muzyka
    sf::Music muzyka;

    if(!muzyka.openFromFile("Music/Chicken.ogg")) {
        std::cout << "Nie mozna zaladowac muzyki!" << '\n';
    }

    muzyka.play();
    muzyka.setLoop(true);


    while(gra.getWindow().isOpen()){

        gra.update();
        gra.render();
    }

    return 0;
}
