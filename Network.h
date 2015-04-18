#ifndef __LD32_NETWORK_H__
#define __LD32_NETWORK_H__

#include "City.h"
#include <vector>

const int num_cities = 5;

class Network
{
public:
    Network();
    ~Network();

    void init();

    void addPath(int a, int b);
    void destroyNode(int n);

    bool isValidPath(std::vector<int> path);
    std::vector<int> getNeighbours(int id);
private:
    City cities[num_cities];
    bool adjacency_table[num_cities][num_cities];

    void changePath(int a, int b, bool value);
};

#endif