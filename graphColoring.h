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

/********************************node类*********************************/

class node {
public:
    node(int _ID);
    ~node();
    void initial(vector<vector<int>> _incidenceMatrix);
    void update(int _edgeID);

    int getID() const;

    int getDegree() const;

    int getOrder() const;

    int getColor() const;

    const map<int, vector<int>> &getMapEdgeID2AdjacencyNodeID() const;

    void setOrder(int order);

    void setColor();

    void setVecCandidateColor(int _colorNum, map<int, node *> _mapNodeID2NodePtr);

private:
    int ID; //编号 从0开始
    int degree; //度
    int color; //节点的颜色
    int order; //着色顺序 从0开始
    vector<int> vecEdgeID; //节点相邻边的ID 从0开始
    vector<int> vecAdjacencyNodeID; //普通边相邻节点ID 从0开始
    map<int, vector<int>> mapEdgeID2AdjacencyNodeID; //相邻边的ID对相邻节点ID的映射表
    vector<int> vecCandidateColor; //节点候选颜色集
};

/********************************hyperNode类*********************************/

class hyperNode {
public:
    hyperNode(int _ID);
    ~hyperNode();
    void initial(vector<vector<int>> _incidenceMatrix);
    void update(int _edgeID);

    int getID() const;

    int getDegree() const;

    int getOrder() const;

    int getColor() const;

    const map<int, vector<int>> &getMapEdgeID2AdjacencyNodeID() const;

    void setOrder(int order);

    void setColor();

    void setVecCandidateColor(int _colorNum, map<int, hyperNode *> _mapNodeID2HyperNodePtr);

private:
    int ID; //编号 从-开始
    int degree; //度
    int color; //节点的颜色
    int order; //着色顺序 从-开始
    vector<int> vecEdgeID; //节点相邻边的ID 从0开始
    vector<int> vecNormalEdgeID; //节点相邻普通边的ID
    vector<int> vecHyperEdgeID; //节点相邻超边的ID
    vector<int> vecNorAdjNodeID; //普通边相邻节点ID 从0开始
    vector<vector<int>> vecHyperAdjNodeID; //超边相邻节点ID 从0开始
    map<int, vector<int>> mapEdgeID2AdjacencyNodeID; //相邻边的ID对相邻节点ID的映射表
    map<int, vector<int>> mapHyperEdgeID2AdjNodeID; //相邻超边的ID对相邻节点ID集合的映射表
    vector<int> vecCandidateColor; //节点候选颜色集
};

/********************************功能函数*********************************/

bool comDegree(node* _node1, node* _node2);
bool comOrder(node* _node1, node* _node2);

bool comhyperDegree(hyperNode* _node1, hyperNode* _node2);
bool comhyperOrder(hyperNode* _node1, hyperNode* _node2);

void graghColoring(map<int, node*> _mapNodeID2NodePtr, int _colorNum);
void hypergraghColoring(map<int, hyperNode*> _mapNodeID2HyperNodePtr, int _colorNum);

#endif //GRAPHCOLORING_GRAPHCOLORING_H
