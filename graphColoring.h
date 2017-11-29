//
// Created by lee on 17-11-29.
//

#ifndef GRAPHCOLORING_GRAPHCOLORING_H
#define GRAPHCOLORING_GRAPHCOLORING_H

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class node {
public:
    node(int _ID);
    ~node();
    void initial(vector<vector<int>> _incidenceMatrix);
    void update(int _edgeID, int _adjacencyNodeID);

    int getID() const;

    int getDegree() const;

    int getOrder() const;

    int getColor() const;

    const map<int, vector<int>> &getMapEdgeID2AdjacencyNodeID() const;

    void setOrder(int order);

    void setColor();

    void setVecCandidateColor(int _colorNum, map<int, node *> _mapNodeID2NodePtr);

private:
    int ID; //编号 从-开始
    int degree; //度
    int color; //节点的颜色
    int order; //着色顺序 从-开始
    vector<int> vecEdgeID; //节点相邻边的ID 从0开始
    vector<int> vecAdjacencyNodeID; //普通边相邻节点ID 从0开始
    map<int, vector<int>> mapEdgeID2AdjacencyNodeID; //相邻边的ID对相邻节点ID的映射表
    vector<int> vecCandidateColor; //节点候选颜色集
};

bool comDegree(node* _node1,node* _node2);
bool comOrder(node* _node1,node* _node2);

void graghColoring(map<int, node*> _mapNodeID2NodePtr, int _colorNum);

#endif //GRAPHCOLORING_GRAPHCOLORING_H
