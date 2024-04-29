#include "Rectangle.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Rectangle::Rectangle(Vector2f size)
{
    this->shape = RectangleShape(size);
    this->speed = Vector2f(0, 0);
    this->objective = Vector2f(0, 0);
    shape.setFillColor(Color::Red);
}

Rectangle::Rectangle(Vector2f size, Vector2i position)
{
    this->shape = RectangleShape(size);
    this->speed = Vector2f(0, 0);
    this->objective = Vector2f(position);
    shape.setFillColor(Color::Red);
    shape.setPosition(position.x, position.y);
}

void Rectangle::update()
{
    this->shape.move(this->speed);
    if(this->shape.getPosition().x - this->objective.x < 5 && this->shape.getPosition().y - this->objective.y < 5){
        this->speed = Vector2f(0, 0);
        this->shape.setFillColor(Color::Green);
    }else{
        this->shape.setFillColor(Color::Red);
    }
}

void Rectangle::setObjective(Vector2f objective)
{
    float a, b, mag, direX, direY;
    this->objective.x = Mouse::getPosition().x;
    this->objective.y = Mouse::getPosition().y;
    a = objective.x;
    b = objective.y;
    direX = a - this->shape.getPosition().x;
    direY = b - this->shape.getPosition().y;
    mag = sqrt(direX*direX + direY*direY);
    this->speed = Vector2f((direX/mag), (direY/mag));
}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}
