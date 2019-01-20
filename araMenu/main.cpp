#define _WIN32_WINNT 0x0500
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Messages.h"
#include "wczytaj.h"
#include <unistd.h>



int a;
sf::Vector2i mouse_position;
bool mouse_pressed = 0;

bool isLoadingSave=0;

int main()
{
    //ShowWindow( hWnd, SW_HIDE );
    sf::RenderWindow window(sf::VideoMode(1000, 720), "A.R.A");

    sf::Texture tlo;
    if (!tlo.loadFromFile("img\\backgroundImage.png"))
    {
        ms_error(12, "nie zaladowano menuBackground", true);
    }
    sf::Sprite Tlo;
    Tlo.setTexture(tlo);

    sf::Texture loading;
    if (!loading.loadFromFile("img\\loadingSave.png"))
    {
        ms_error(12, "nie zaladowano loadingSave", true);
    }
    sf::Sprite Loading;
    Loading.setTexture(loading);
    //window.draw(Loading);

    sf::Texture play;
    if (!play.loadFromFile("img\\play.png"))
    {
        ms_error(19, "nie zaladowano play", true);
    }
    sf::Sprite Play;
    Play.setTexture(play);
    Play.setPosition(sf::Vector2f(300, 150));
    Play.setScale(sf::Vector2f(1.5, 1.5));


    sf::Texture exit;
    if (!exit.loadFromFile("img\\exit.png"))
    {
        ms_error(24, "exit", true);
    }
    sf::Sprite Exit;
    Exit.setTexture(exit);
    Exit.setPosition(sf::Vector2f(400, 550));
    Exit.setScale(sf::Vector2f(0.6, 0.6));

    sf::Texture wczytaj;
    if (!wczytaj.loadFromFile("img\\wczytaj.png"))
    {
        ms_error(30, "nie zaladowano edit", true);
    }
    sf::Sprite Wczytaj;
    Wczytaj.setTexture(wczytaj);
    Wczytaj.setPosition(sf::Vector2f(300, 350));
    Wczytaj.setScale(sf::Vector2f(1.2, 1.2));

    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        mouse_pressed = 0;

        mouse_position = sf::Mouse::getPosition(window);
        while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mouse_position = sf::Mouse::getPosition(window);
            mouse_pressed = 1;
        }
        if(mouse_pressed&&!isLoadingSave){
            if(mouse_position.x>=300&&mouse_position.x<680&&mouse_position.y>150&&mouse_position.y<280){
                saveToFile(0);
                window.close();
                system("..\\..\\..\\bin\\Debug\\ara.exe");

            }else if (mouse_position.x>=300&&mouse_position.x<707&&mouse_position.y>358&&mouse_position.y<473){
                isLoadingSave=1;
                //usleep(microseconds);
            }else if(mouse_position.x>=400&&mouse_position.x<560&&mouse_position.y>550&&mouse_position.y<630){
                window.close();
                return 0;
            }

        }
        if(isLoadingSave){
            mouse_pressed=0;
            while(true){
                mouse_pressed = 0;
                if(isLoadingSave)window.draw(Loading);
                window.display();
                while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    mouse_position = sf::Mouse::getPosition(window);
                    mouse_pressed = 1;
                }
                if(mouse_pressed){
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>30&&mouse_position.y<130){
                        saveToFile(1);
                        window.close();
                        system("..\\..\\..\\bin\\Debug\\ara.exe");
                    }
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>170&&mouse_position.y<290){
                        saveToFile(2);
                        window.close();
                        system("..\\..\\..\\bin\\Debug\\ara.exe");
                    }
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>320&&mouse_position.y<430){
                        saveToFile(3);
                        window.close();
                        system("..\\..\\..\\bin\\Debug\\ara.exe");
                    }
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>470&&mouse_position.y<570){
                        saveToFile(4);
                        window.close();
                        system("..\\..\\..\\bin\\Debug\\ara.exe");
                    }
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>610&&mouse_position.y<710){
                       saveToFile(5);
                       window.close();
                       system("..\\..\\..\\bin\\Debug\\ara.exe");
                    }
                }
            }
        }






        window.draw(Tlo);
        window.draw(Wczytaj);
        window.draw(Play);
        window.draw(Exit);
        if(isLoadingSave)window.draw(Loading);
        window.display();


        //window.clear();
        //std::cin>>a;
        /*if(a==1){
            window.close();
            system("..\\..\\..\\bin\\Debug\\ara.exe");

        }*/
    }
}
