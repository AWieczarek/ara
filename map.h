#include "lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#include "lib/SFML-2.5.1/include/SFML/Window.hpp"

class Window
{
public:
    sf::RenderWindow window;
    void GameLoop();
};

class Pole:public sf::Sprite{

public:
    std::string name;
    int owner;  //0-puste           1-gracz 1            2- gracz 2

};

class Background : public Window
{
    public:
    sf::Texture Field;
    sf::Sprite fields[17][34];
    Background();
    void start();
    void draw();
};

class Rudy : public Window
{
    public:
    sf::Texture rudys;
    sf::Sprite rudy;
    Rudy();
    void start();
    void draw();
};
