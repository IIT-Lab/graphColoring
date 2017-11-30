#include <iostream>
#include <vector>
#include <map>
//#include "algorithm.h"
#include "graphColoring.h"

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
        {1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {0,1,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0},
};

map<int, map<int, int>> hypergraphIncidenceMatrix;

int main() {
    int colorNum = 3;
    /********************************普通图*********************************/
//    int nodeNum = (int)incidenceMatrix.size();
//    map<int, node*> mapNodeID2NodePtr;
//
//    for (int i = 0; i < nodeNum; ++i) {
//        node* nodePtr = new node(i);
//        nodePtr->initial(incidenceMatrix);
//        mapNodeID2NodePtr.insert(pair<int, node*>(i, nodePtr));
//    }
//
//    graghColoring(mapNodeID2NodePtr, colorNum);

    /********************************超图*********************************/
    int nodeNum = (int)hypergraph.size();
    map<int, hyperNode*> mapNodeID2HyperNodePtr;

    for (int i = 0; i < nodeNum; ++i) {
        hyperNode* hyperNodePtr = new hyperNode(i);
        hyperNodePtr->initial(hypergraph);
        mapNodeID2HyperNodePtr.insert(pair<int, hyperNode*>(i, hyperNodePtr));
    }

    hypergraghColoring(mapNodeID2HyperNodePtr, colorNum);

    return 0;
}

//int main() {

//    graghColoringByAdjacencyMatrix(adjacencyMatrix);

//    adjacency2Incidence(adjacencyMatrix, incidenceMatrix);

//    graghColoringByIncidenceMatrix(incidenceMatrix);

//    map<int, int> tempHypergraph;
//
//    for (int i = 0; i < hypergraph.size(); ++i) {
//        tempHypergraph.clear();
//        for (int j = 0; j < hypergraph.at(0).size(); ++j) {
//            tempHypergraph.insert(pair<int, int>(j, hypergraph[i][j]));
//        }
//        hypergraphIncidenceMatrix.insert(pair<int, map<int, int>>(i, tempHypergraph));
//    }
//    cout << "hypergraphIncidenceMatrix:" << endl;
//    for (int m = 0; m < hypergraph.size(); ++m) {
//        for (int i = 0; i < hypergraph.at(0).size(); ++i) {
//            cout << hypergraphIncidenceMatrix[m][i] << ",";
//        }
//        cout << endl;
//    }
//
//    hypergraghColoring(hypergraphIncidenceMatrix);
//
//    return 0;
//}