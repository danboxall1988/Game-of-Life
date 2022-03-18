#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdio>
#include <iostream>
#include <vector>
#include "cell.hpp"
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string> 

using namespace sf;
using namespace std;

class Button {
    public:
        Button(void);
        bool checkCollision(sf::Vector2f&);
        sf::Texture loadTexture(void);
        sf::Sprite button;
        sf::Texture img;
        string txt;
};

Button::Button(void) {
    img = loadTexture();
    button.setTexture(img);
    button.setPosition(sf::Vector2f(200,200));
}

bool Button::checkCollision(sf::Vector2f& mpos) {
    /* sf::Vector2u bsize = img.getSize(); */
    /* sf::Vector2f bpos = button.getPosition(); */
    /* if (mpos.x > bpos.x && mpos.x < bpos.x + bsize.x) */
    /*     if (mpos.y > bpos.y && mpos.y < bpos.y + bsize.y) */
    /*         return false; */
    /* return true; */
    sf::IntRect btn = button.getTextureRect();
    printf("x = %f, y = %f\n", mpos.x, mpos.y);
    return btn.contains(mpos.x, mpos.y);
 } 

sf::Texture Button::loadTexture(void) {
    sf::Texture texture;
    if (!texture.loadFromFile("button.png")) {
        cout << "image not found!" << endl;
    }
    return texture;
}

void event_loop(RenderWindow& window, Button& b) {
    Event e;
    Vector2f mousePos;
    while (window.pollEvent(e)) {
        if (e.type == Event::KeyPressed)
            window.close();
        if (e.type == Event::MouseButtonPressed) {
            sf::Vector2f pos = b.button.getPosition();
            cout << b.checkCollision(pos) << endl;
        }
    }
}

 int main(void) {
    RenderWindow window(VideoMode(600, 600), "test");
    Button b;

    while (window.isOpen()) { 
        event_loop(window, b); 
        window.clear(Color::White);
        window.draw(b.button);
        window.display();
     } 
    return 0;
}
