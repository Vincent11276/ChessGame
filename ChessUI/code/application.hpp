#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Application
{
private:
    sf::RenderWindow window;
    sf::Clock clock;

public:
    sf::Color backgroundColor;

    Application(sf::VideoMode mode, const std::string &title) 
        : window(mode, title)
    {
        this->window.setVerticalSyncEnabled(true);
    }

    void run()
    {
        this->awake();

        while (this->window.isOpen())
        {
            float delta = clock.restart().asSeconds();

            // Events
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    this->window.close();
                    break;
                
                default:
                    break;
                }
            }
            // external event handler
            this->handleEvents(event);

            // update
            this->update(delta);

            // draw
            this->window.clear();
            this->draw(this->window);
            this->window.display();
        }
    }

protected:
    virtual void awake() = 0;
    virtual void handleEvents(sf::Event &event) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};