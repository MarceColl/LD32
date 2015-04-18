#ifndef __SFMS_INPUTMANAGER_H_
#define __SFMS_INPUTMANAGER_H_

#include <SFML\Graphics.hpp>
#include <map>

class InputManager
{
public:
    InputManager(sf::RenderWindow* window);
    ~InputManager();

    void update();

private:
    void initializeInputMapping();
    void addKeyboardMapping(sf::Keyboard::Key input_k);
    void addMouseMapping(sf::Mouse::Button input_b);
    void parseEvents(sf::Event event);
    sf::Vector2i getMousePosition();

    std::map<sf::Keyboard::Key, bool> keyboard_map;
    std::map<sf::Mouse::Button, bool> mouse_map;
    sf::RenderWindow* window;
    sf::Vector2i mousePos;
};

#endif