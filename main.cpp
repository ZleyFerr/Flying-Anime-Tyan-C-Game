#include <iostream>
#include <SFML/Graphics.hpp>

sf::Image img;
sf::Texture texture;
sf::Sprite spr;
float deltaTime;
double dt;


int main() {
    sf::Clock clock;
    deltaTime = clock.restart().asSeconds();
    dt = deltaTime * 350000;
    float speed = 0.5;
    img.loadFromFile("Player.png");
    texture.loadFromImage(img);
    spr.setTexture(texture);
    spr.setScale(0.1, 0.1);
    spr.setPosition(100, 100);
    sf::RenderWindow win(sf::VideoMode(1920, 1080), "Eternal Dungeons");
    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        std::cout << "deltatime = " << dt << std::endl;
        //”правление
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            spr.move(0, -speed*dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            spr.move(0, speed*dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            spr.move(speed*dt, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            spr.move(-speed*dt, 0);
        }
        //
        win.clear(sf::Color(142,11,165));
        win.draw(spr);
        win.display();
    }
}