#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    // setup
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    Rectangle rect(Vector2f(30,30));

    // loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
                if(event.type = Mouse::isButtonPressed(left)){
                    rect.update();
                };
        }

        window.clear();
        rect.update();
        rect.drawTo(window);
        window.display();
    }

    return 0;
}
