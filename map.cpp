#include "map.h"


void Game::Background()
{
    if (!Field.loadFromFile("img/dupa.png"))
    {

    }
}

void Game::start_B()
{
    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {
                    fields[i][j].setTexture(Field);
                    fields[i][j].setScale(sf::Vector2f(0.2f, 0.2f));
                    fields[i][j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
                }
            }
            else
            {
                if(j%2==1)
                {
                    fields[i][j].setTexture(Field);
                    fields[i][j].setScale(sf::Vector2f(0.2f, 0.2f));
                    fields[i][j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
                }
            }
        }
    }

    for (int i = 0; i<8;++i)
    {
        for (int j = 0; j<8; ++j)
        {
            if((j-i)>=0)
            {
                fields[i][j-i].setColor(sf::Color(0,0,0));
                fields[i][26+j].setColor(sf::Color(0,0,0));
            }
            else
            {
                fields[9+i][j].setColor(sf::Color(0,0,0));
                fields[9+i][32-j].setColor(sf::Color(0,0,0));
            }
        }
    }
}

void Game::Rudy()
{
    if (!rudys.loadFromFile("img/rudy.png"))
    {

    }
}

void Game::start_Rudy()
{
    rudy.setTexture(rudys);
    rudy.setOrigin(250, 297);
    rudy.setPosition(sf::Vector2f(1366/2.0f,720/2.0f));
    sf::Vector2f scale = rudy.getScale();
    rudy.setScale(sf::Vector2f(0.5f, 0.5f));
}


void Game::Window()
{
     window.create(sf::VideoMode(1366, 720), "My window");
}
void Game::GameLoop()
{
    Window();
    Background();
    start_B();
    Rudy();
    start_Rudy();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i<17; ++i)
        {
            for (int j = 0; j<33; ++j)
            {
                window.draw(fields[i][j]);
            }
        }
        window.draw(rudy);

        window.display();
        //window.clear(sf::Color(200, 0, 0));
    }
}

