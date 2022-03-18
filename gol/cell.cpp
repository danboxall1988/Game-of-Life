#include "cell.hpp"

Cell::Cell(int x, int y) : x(this->x), y(this->y) {
    img.setSize(sf::Vector2f(size, size));
    img.setPosition(x, y);
    img.setFillColor(sf::Color::Blue);
    currentState = DEAD;
}

int Cell::X(void) {
    return x;
}

int Cell::Y(void) {
    return y;
}

sf::RectangleShape Cell::getImg(void) {
    return img;
}

void Cell::changeState(state s) {
    currentState = s;
}

state Cell::getState(void) {
    return currentState;
}
