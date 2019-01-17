#include "map.h"

void Window::GameLoop()
{
    window.setTitle("SFML window");
    window.setSize(sf::Vector2u(1366, 720));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
        window.clear();
    }
}

Background::Background()
{
    if (!Field.loadFromFile("img/dupa.png"))
    {

    }
}

void Background::start()
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
void Background::draw()
{
    for (int i = 0; i<17; ++i)
    {
        for (int j = 0; j<33; ++j)
        {
            window.draw(fields[i][j]);
        }
    }
}

Rudy::Rudy()
{
    if (!rudys.loadFromFile("img/rudy.png"))
    {
        // error...
    }
}

void Rudy::start()
{
    rudy.setTexture(rudys);
    rudy.setOrigin(250, 297);
    rudy.setPosition(sf::Vector2f(1366/2.0f,720/2.0f));
    sf::Vector2f scale = rudy.getScale();
    rudy.setScale(sf::Vector2f(0.5f, 0.5f));
}

void Rudy::draw()
{
    window.draw(rudy);
}
