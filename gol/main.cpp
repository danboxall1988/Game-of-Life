#include "main.hpp"

Board board;

int main(void) {
    sf::RenderWindow window(sf::VideoMode(WINSIZE, WINSIZE), "Game of Life");
    window.setFramerateLimit(1);

    for (int i = 0; i < 15; i++) {
        board.cells[25][15+i].changeState(ALIVE);
    }

    while (window.isOpen()) {
        event_loop(window);
        window.clear(sf::Color::White);
        board.drawCells(window);
        //board.printCells();
        board.checkCells();
        //makeChanges();
        board.changeStates();
        window.display();
    }
    return 0;
}

void event_loop(sf::Window& win) {
    sf::Event e;
    while (win.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            win.close();
        if (e.type == sf::Event::KeyPressed)
            if(e.key.code == sf::Keyboard::Enter)
                win.close();
        if (e.type == sf::Event::MouseButtonPressed) {
            //setCellState(e.mouseButton.x, e.mouseButton.y);
        }        
    }
}

void setCellState(int x, int y) {
    int xCoord = x / Cell::size;
    int yCoord = y / Cell::size;
    Cell& c = board.cells[yCoord][xCoord];
    c.changeState(ALIVE);
}

