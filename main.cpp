#include <iostream>
#include <vector>
#include <map>
#include "algorithm.h"

using namespace std;

vector<vector<int>> adjacencyMatrix = {  //邻接矩阵 Adjacency Matrix
        {0, 1, 1, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 1, 1, 0},
        {1, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 0},
};

//map<int, map<int, int>> incidenceMatrix; //Incidence Matrix 行号是节点号，列号是边号

vector<vector<int>> incidenceMatrix = { //Incidence Matrix 行号是节点号，列号是边号
        {1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
        {1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
        {0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,0},
        {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
};

vector<vector<int>> hypergraph = { //Incidence Matrix 行号是节点号，列号是边号
        {1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {0,1,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,0,1},
        {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0},
};

map<int, map<int, int>> hypergraphIncidenceMatrix;

int main() {

//    graghColoringByAdjacencyMatrix(adjacencyMatrix);

//    adjacency2Incidence(adjacencyMatrix, incidenceMatrix);

//    graghColoringByIncidenceMatrix(incidenceMatrix);
    map<int, int> tempHypergraph;

    for (int i = 0; i < hypergraph.size(); ++i) {
        tempHypergraph.clear();
        for (int j = 0; j < hypergraph.at(0).size(); ++j) {
            tempHypergraph.insert(pair<int, int>(j, hypergraph[i][j]));
        }
        hypergraphIncidenceMatrix.insert(pair<int, map<int, int>>(i, tempHypergraph));
    }
    cout << "hypergraphIncidenceMatrix:" << endl;
    for (int m = 0; m < hypergraph.size(); ++m) {
        for (int i = 0; i < hypergraph.at(0).size(); ++i) {
            cout << hypergraphIncidenceMatrix[m][i] << ",";
        }
        cout << endl;
    }

    hypergraghColoring(hypergraphIncidenceMatrix);

    return 0;
}