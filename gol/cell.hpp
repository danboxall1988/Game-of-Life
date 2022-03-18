#ifndef CELL_HPP
#define CELL_HPP 

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp> 
#include <SFML/Main.hpp> 

enum state {DEAD, ALIVE};

class Cell {
    public:
        static const int size = 15;
        Cell(int, int);
        int X(void);
        int Y(void);
        sf::RectangleShape getImg(void);
        void changeState(state s);
        state getState(void);
    private:
        sf::RectangleShape img;
        const int x;
        const int y;
        state currentState;
};

#endif
