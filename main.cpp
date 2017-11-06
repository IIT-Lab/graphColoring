#include <iostream>
#include <vector>
#include "algorithm.h"

using namespace std;

vector<vector<int>> map = {  //邻接矩阵 Adjacency Matrix
        {0, 1, 1, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 0},
};

int main() {

    graghColoringByAdjacencyMatrix(map);

    return 0;
}