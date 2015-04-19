#ifndef __LD32_NETWORK_H__
#define __LD32_NETWORK_H__

#include "City.h"
#include "Beasts.h"
#include <vector>

const int num_cities = 5;

class Network
{
public:
    Network(Game* g);
    ~Network();

    void init();

    /**
     * Set an edge between two nodes
     */
    void addPath(int a, int b);

    /**
     * Set all edges to this node as invalids
     */
    void destroyNode(int n);

    bool isValidPath(std::vector<int> path);

    /**
     * Returns a vector with all the neighbors
     * for a node
     */
    std::vector<int> getNeighbours(int id);

    /**
     * Returns a pointer to the given city id
     */
    City* getCity(int id);

    /**
     * Given coords, returns the city ID or 
     * otherwise returns -1
     */
    int getCityByCoords(sf::Vector2f coords);


private:
    City* cities;
    bool adjacency_table[num_cities][num_cities];

    void changePath(int a, int b, bool value);
    Game* game;
};

#endif
