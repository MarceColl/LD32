#include "Network.h"

#include<vector>

Network::Network() {
    init();
}

void Network::init() {
    for (int i = 0; i < num_cities; i++) {
        cities[i] = City(i);
        for (int j = 0; j < num_cities; j++) {
            adjacency_table[i][j] = false;
        }
    }
}

Network::~Network() {}

void Network::addPath(int a, int b) {
    changePath(a, b, true);
}

void Network::destroyNode(int n) {
    for (int i = 0; i < num_cities; i++) {
        changePath(n, i, false);
    }
}

void Network::changePath(int a, int b, bool value) {
    adjacency_table[a][b] = b; 
    adjacency_table[b][a] = b;
}

// Crec que hauria de funcionar, no n'estic gens segur per aixo haha
bool Network::isValidPath(std::vector<int> path) {
    bool adj_table[num_cities][num_cities];
    memcpy(adj_table, adjacency_table, sizeof(adjacency_table));

    int previous = path[0];
    std::vector<int>::iterator it = path.begin; it++;
    for (; it != path.end; it++) {
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

// Tampoc tinc molt clar si funcionara, estava parlant de kung fu
std::vector<int> Network::getNeighbours(int id) {
    std::vector<int> yoloswag;

    for (int i = 0; i < num_cities; i++) {
        if (adjacency_table[id][i] == true) {
            yoloswag.push_back(i);
        }
    }

    return yoloswag;
}