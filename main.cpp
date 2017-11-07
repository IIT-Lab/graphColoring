#include <iostream>
#include <vector>
#include <map>
#include "algorithm.h"

using namespace std;

vector<vector<int>> adjacencyMatrix = {  //邻接矩阵 Adjacency Matrix
        {0, 1, 1, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 0},
};

map<int, map<int, int>> incidenceMatrix; //Incidence Matrix 行号是节点号，列号是边号

int main() {

    graghColoringByAdjacencyMatrix(adjacencyMatrix);

    adjacency2Incidence(adjacencyMatrix, incidenceMatrix);

    graghColoringByIncidenceMatrix(incidenceMatrix);

    return 0;
}