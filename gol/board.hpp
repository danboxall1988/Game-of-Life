#ifndef BOARD_HPP
#define BOARD_HPP 

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <cstdio>
#include "cell.hpp"
#include "main.hpp"

struct directions {
    int NW[2] = {-1, -1};
    int N [2] = {0,  -1};
    int NE[2] = {1,  -1};
    int E [2] = {1,   0};
    int SE[2] = {1,   1};
    int S [2] = {0,   1};
    int SW[2] = {-1,  1};
    int W [2] = {-1,  0};
}; 

class Board {
    public:
        std::vector< std::vector<int> > deaths;
        std::vector< std::vector<int> > births;
        int cellsPerRow;
        Board(void);
        std::vector< std::vector<Cell> > cells;
        void drawCells(sf::RenderWindow&);
        void checkCells(void);
        void changeStates(void); 
        void printCells(void);
    private:
        const struct directions dirs;
        void initBoard(void);
        void initCells(void);
        int checkNeighbours(int, int);
};

#endif
