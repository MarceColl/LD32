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
    Beast::Attributes attr(5, 30, 40, 5, 64, 100);

    Beasts beasts = Beasts(game, attr);

    sf::Vector2f initialPositions[num_cities] = {
        sf::Vector2f(45, 750),
        sf::Vector2f(67, 430),
        sf::Vector2f(560, 750),
        sf::Vector2f(500, 400),
        sf::Vector2f(300, 150),
        sf::Vector2f(900, 550),
        sf::Vector2f(870, 170),
        sf::Vector2f(1200, 70),
        sf::Vector2f(1100, 450)
    };

    std::string cityNames[num_cities] = {
        "Crapstone",
        "Ugley-doo",
        "Humansville",
        "Lickfork",
        "Beaver Cataclysm",
        "Pontypridd",
        "Sheep Stallion",
        "Ho-Ho-Kus",
        "Humptulips"
    };

    for (int i = 0; i < num_cities; i++) {
        City c = City(game, i, cityNames[i], beasts);
        c.setPosition(initialPositions[i]);
        cities.push_back(c);
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
    //drawPaths();
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
