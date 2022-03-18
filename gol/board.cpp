#include "board.hpp"
#include <vector>

Board::Board(void) {
    cellsPerRow = WINSIZE / Cell::size;
    initCells();
    std::cout << cellsPerRow << std::endl;
}

void Board::initCells(void) {
    int cs = Cell::size;
    for (int row = 0; row < cellsPerRow; row++) {
        std::vector<Cell> r;
        for (int col = 0; col < cellsPerRow; col++) {
            Cell c(cs*col, cs*row);
            r.push_back(c);
        }
        cells.push_back(r);
    }
}

void Board::printCells(void) {
    for (auto row : cells) {
        for (Cell c : row) {
            if (c.getState() == ALIVE)
                std::cout << "*";
            else
                std::cout << " ";
        }     
        std::cout << std::endl;
    }           
}

void Board::drawCells(sf::RenderWindow& w) {
    for (auto row : cells)
        for (Cell c : row)
            if (c.getState() == ALIVE)
                w.draw(c.getImg());
}

void Board::checkCells(void) {
    births.clear();
    deaths.clear();
    for (int row = 1; row < cellsPerRow -1; row++) {
        for (int col = 1; col < cellsPerRow -1; col++) {
            Cell& c = cells[row][col];
            state cstate = c.getState(); 
            int liveNeighbours = checkNeighbours(row, col);
            if (cstate == ALIVE) {
                if (liveNeighbours > 3 || liveNeighbours < 2) {
                    std::vector<int> d  = {row, col};
                    deaths.push_back(d);
                }
            } else {
                if (liveNeighbours == 3) {
                    std::vector<int> b = {row, col};
                    births.push_back(b);
                }
            }
        } 
    }
}

int Board::checkNeighbours(int row, int col) {
    int liveNeighbours = 0;
    Cell *neighbour = (Cell *) malloc(sizeof(Cell));

    // check northwest
    liveNeighbours += cells[row + dirs.NW[1]][col + dirs.NW[0]].getState();
    // check North
    liveNeighbours += cells[row + dirs.N[1]][col + dirs.N[0]].getState();
    // check northeast
    liveNeighbours += cells[row + dirs.NE[1]][col + dirs.NE[0]].getState();
    // check East
    liveNeighbours += cells[row + dirs.E[1]][col + dirs.E[0]].getState();
    // check southeast
    liveNeighbours += cells[row + dirs.SE[1]][col + dirs.SE[0]].getState();
    // check south
    liveNeighbours += cells[row + dirs.S[1]][col + dirs.S[0]].getState();
    // check southwestj
    liveNeighbours += cells[row + dirs.SW[1]][col + dirs.SW[0]].getState();
    // check west
    liveNeighbours += cells[row + dirs.W[1]][col + dirs.W[0]].getState();
    return liveNeighbours;
}


void Board::changeStates(void) {
    for (auto d : deaths) 
        cells[d[0]][d[1]].changeState(DEAD);
    for (auto b : births)
        cells[b[0]][b[1]].changeState(ALIVE);
}
