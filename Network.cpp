#include"Network.h"
#include<string.h>
#include<vector>
#include "Game.h"
#include "Beasts.h"

Network::Network(Game* g) 
    : game(g), window(game->getWindow())
{
    init();
}

void Network::init() {
    Beasts beasts = Beasts(game, 100, 100, 100, 100, 100, 100);

    sf::Vector2f initialPositions[num_cities] = {
        sf::Vector2f(750, 800),
        sf::Vector2f(500, 750),
        sf::Vector2f(450, 600),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
        sf::Vector2f(750, 800),
    };

    for (int i = 0; i < num_cities; i++) {
        City c = City(game, i, beasts);
        c.setPosition(initialPositions[i]);
        cities.push_back();
        for (int j = 0; j < num_cities; j++) {
            adjacency_table[i][j] = false;
        }
    }
}

Network::~Network() {
}

void Network::addPath(int a, int b) {
    changePath(a, b, true);
}

void Network::destroyNode(int n) {
    for (int i = 0; i < num_cities; i++) {
        changePath(n, i, false);
    }
}

void Network::draw() {
    drawPaths();
    for (std::vector<City>::iterator it = cities.begin(); it != cities.end(); it++) {
        it->draw();
    }

    for (std::vector<City>::iterator it = cities.begin(); it != cities.end(); it++) {
        it->drawPopup();
    }
}

void Network::update() {
    for (std::vector<City>::iterator it = cities.begin(); it != cities.end(); it++) {
        it->update();
    }
}

void Network::drawPaths() {
    for (std::vector<City>::iterator it = cities.begin(); it != cities.end(); it++) {
        sf::Vector2f c_position = it->getCenteredPosition();
        std::vector<int> neighbours = getNeighbours(it->getId());
        for (std::vector<int>::iterator iit = neighbours.begin(); iit != neighbours.end(); iit++) {
            sf::Vector2f o_position = cities[*iit].getCenteredPosition();
            sf::Vertex line[] = {
                sf::Vertex(c_position),
                sf::Vertex(o_position)
            };
            window->draw(line, 2, sf::Lines);
        }
    }
}

void Network::changePath(int a, int b, bool value) {
    adjacency_table[a][b] = value; 
    adjacency_table[b][a] = value;
}

// Crec que hauria de funcionar, no n'estic gens segur per aixo haha
bool Network::isValidPath(std::vector<int> path) {
    bool adj_table[num_cities][num_cities];
    memcpy(adj_table, adjacency_table, sizeof(adjacency_table));

    int previous = path[0];
    std::vector<int>::iterator it = path.begin(); it++;
    for (; it != path.end(); it++) {
        if (adj_table[*it][previous] == true) {
            changePath(*it, previous, false);
            previous = *it;
        }
        else {
            return false;
        }
    }
    return true;
}

City* Network::getCity(int id) {
    return &cities[id];
}

// Tampoc tinc molt clar si funcionara, estava parlant de kung fu
std::vector<int> Network::getNeighbours(int id) {
    std::vector<int> neighbours;

    for (int i = 0; i < num_cities; i++) {
        if (adjacency_table[id][i] == true) {
            neighbours.push_back(i);
        }
    }

    return neighbours;
}

int Network::getCityByCoords(sf::Vector2f coords) {
    for (int i = 0; i < num_cities; i++) {
        if (cities[i].isInside(coords)) {
            return i;
        }
    }

    return -1;
}
