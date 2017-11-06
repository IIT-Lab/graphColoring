//
// Created by lee on 17-11-6.
//

#ifndef GRAPHCOLORING_ALGORITHM_H
#define GRAPHCOLORING_ALGORITHM_H

#include <iostream>

using namespace std;

struct Node{ //定义节点结构体
    int index; //编号
    int degree; //度
    int color; //改节点的颜色
};

bool com(Node node1,Node node2);

bool com2(Node node1,Node node2);

void graghColoringByAdjacencyMatrix(vector<vector<int>> map);

//void graghColoringByIncidenceMatrix(vector<vector<int>> map);

#endif //GRAPHCOLORING_ALGORITHM_H
