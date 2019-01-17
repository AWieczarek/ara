#include "lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#include "lib/SFML-2.5.1/include/SFML/Window.hpp"
#include <iostream>

class Pole:public sf::Sprite{

public:
    std::string name;
    int owner;  //0-puste           1-gracz 1            2- gracz 2

};

class Game
{
    public:
    sf::RenderWindow window;
    sf::Texture Field;
    sf::Sprite fields[17][34];
    sf::Texture rudys;
    sf::Sprite rudy;
    void Background();
    void start_B();
    void Rudy();
    void start_Rudy();
    void Window();
    void GameLoop();

};
