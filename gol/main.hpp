#ifndef MAIN_HPP
#define MAIN_HPP 

#define WINSIZE 750

#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp> 
#include <vector>
#include "cell.hpp"
#include "board.hpp"


void event_loop(sf::Window&);
void setCellState(int, int);

#endif 
