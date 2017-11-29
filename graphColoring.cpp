//
// Created by lee on 17-11-29.
//

#include "graphColoring.h"


node::node(int _ID) {
    ID = _ID;
    degree = -1;
    color = -1;
    order = -1;
}

node::~node() {

}

void node::initial(vector<vector<int>> _incidenceMatrix) {
    //初始化vecEdgeID
    vector<int> vecEdge = _incidenceMatrix[ID];
    for (int edgeID = 0; edgeID < vecEdge.size(); edgeID++) {
        if (vecEdge[edgeID]) {
            vecEdgeID.push_back(edgeID);
        }
    }

    //初始化mapEdgeID2NodeID
    for (int edgeID : vecEdgeID) {
        vector<int> tempvecAdjacencyNodeID; //1条边对应的所有相邻节点ID的集合
        for (int AdjacencyNodeID = 0; AdjacencyNodeID < _incidenceMatrix.size(); ++AdjacencyNodeID) {
            if (AdjacencyNodeID != ID && _incidenceMatrix[AdjacencyNodeID][edgeID]) {
                tempvecAdjacencyNodeID.push_back(AdjacencyNodeID);
            }
        }
        mapEdgeID2AdjacencyNodeID.insert(pair<int, vector<int>>(edgeID, tempvecAdjacencyNodeID));
    }

    for (auto tempvecAdjacencyNodeID : mapEdgeID2AdjacencyNodeID) {
        if (tempvecAdjacencyNodeID.second.size() == 1) {
            vecAdjacencyNodeID.push_back(tempvecAdjacencyNodeID.second[0]);
        }
    }

    degree = (int)vecEdgeID.size();
}

int node::getDegree() const {
    return degree;
}

void node::setOrder(int order) {
    node::order = order;
}

const map<int, vector<int>> &node::getMapEdgeID2AdjacencyNodeID() const {
    return mapEdgeID2AdjacencyNodeID;
}

void node::update(int _edgeID, int _adjacencyNodeID) {
    //更新vecEdgeID //更新mapEdgeID2AdjacencyNodeID
    vector<int> tempvecEdgeID = vecEdgeID; //节点相邻边的ID 从0开始
    map<int, vector<int>> tempmapEdgeID2AdjacencyNodeID = mapEdgeID2AdjacencyNodeID; //相邻边的ID对相邻节点ID的映射表
    vecEdgeID.clear();
    mapEdgeID2AdjacencyNodeID.clear();
    for (int i = 0; i < tempvecEdgeID.size(); ++i) {
        if (tempvecEdgeID[i] != _edgeID) {
            vecEdgeID.push_back(tempvecEdgeID[i]);
            mapEdgeID2AdjacencyNodeID.insert(pair<int, vector<int>>(tempvecEdgeID[i], tempmapEdgeID2AdjacencyNodeID.at(tempvecEdgeID[i])));
        }
    }

    //更新degree
    degree = (int)vecEdgeID.size();

//    //更新vecAdjacencyNodeID
//    vector<int> tempvecAdjacencyNodeID = vecAdjacencyNodeID; //普通边相邻节点ID 从0开始
//    vecAdjacencyNodeID.clear();
//    for (int i = 0; i < tempvecAdjacencyNodeID.size(); ++i) {
//        if (tempvecAdjacencyNodeID[i] != _adjacencyNodeID) {
//            vecAdjacencyNodeID.push_back(tempvecAdjacencyNodeID[i]);
//        }
//    }
}

int node::getID() const {
    return ID;
}

int node::getOrder() const {
    return order;
}

int node::getColor() const {
    return color;
}

void node::setVecCandidateColor(int _colorNum, map<int, node *> _mapNodeID2NodePtr) {
    for (int colorID = 0; colorID < _colorNum; ++colorID) {
        int pushColor = 1;
        for (auto temp : vecAdjacencyNodeID) {
             if (_mapNodeID2NodePtr.at(temp)->getColor() == colorID) pushColor = 0;
        }
        if (pushColor) vecCandidateColor.push_back(colorID);
    }
}

void node::setColor() {
    if (vecCandidateColor.size()) color = vecCandidateColor[0];
    cout << "节点" << ID << ": " << "颜色 " << color << endl;
}

bool comDegree(node *_node1, node *_node2) { //按度从高到低排序
    return _node1->getDegree() > _node2->getDegree();
}

bool comOrder(node *_node1, node *_node2) { //按着色顺序排序
    return _node1->getOrder() < _node2->getOrder();
}

void graghColoring(map<int, node *> _mapNodeID2NodePtr, int _colorNum) {
    int numOfNodes = (int)_mapNodeID2NodePtr.size();
    vector<node*> nodes;
    for (auto _temp : _mapNodeID2NodePtr) {
        nodes.push_back(_temp.second);
    }

    for (int i = 0; i < numOfNodes; ++i) {
        //排序
        sort(nodes.begin(), nodes.end(), comDegree); //按度从高到低排序
        node * tempNode = nodes[0]; //度最大的节点
        tempNode->setOrder(i); //设置着色序号

        //去除节点 去除边 更新子图
        map<int, vector<int>> mapBreakEdgeID2AdjacencyNodeID = tempNode->getMapEdgeID2AdjacencyNodeID();
        for (auto tempVec : mapBreakEdgeID2AdjacencyNodeID) {
            for (auto AdjacencyNodeID : tempVec.second) {
                _mapNodeID2NodePtr.at(AdjacencyNodeID)->update(tempVec.first, tempNode->getID());
            }
        }

        vector<node*> tempNodes = nodes;
        nodes.clear();
        for (int j = 0; j < tempNodes.size(); ++j) {
            if (tempNodes[j]->getID() != tempNode->getID()) {
                nodes.push_back(nodes[j]);
            }
        }
    }

    //按节点着色顺序给节点着色
    for (auto _temp : _mapNodeID2NodePtr) {
        nodes.push_back(_temp.second);
    }

    sort(nodes.begin(), nodes.end(), comOrder); //按着色顺序排序
    for (int k = 0; k < nodes.size(); ++k) {
        nodes[k]->setVecCandidateColor(_colorNum, _mapNodeID2NodePtr);
        nodes[k]->setColor();
    }
}
