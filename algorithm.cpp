//
// Created by lee on 17-11-6.
//
#include <iostream>
#include <algorithm>
#include "algorithm.h"

using namespace std;

bool com(Node node1,Node node2) { //按度从高到低排序
    return node1.degree > node2.degree;
}

bool _com(Node node1,Node node2) { //按度从低到高排序
    return node1.degree < node2.degree;
}

bool _comOrder(Node node1,Node node2) { //按order从低到高排序
    return node1.order < node2.order;
}

bool com2(Node node1,Node node2) { //按节点序号从高到低排序
    return node1.index < node2.index;
}

void graghColoringByAdjacencyMatrix(vector<vector<int>> map) {
    int numOfNodes = int(map.size());

    Node nodes[numOfNodes];

    int m = numOfNodes;
    int n = numOfNodes;
    for (int i = 0; i < m; i++) {//读入数据
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (map[i][j])
                degree++;
        }
        nodes[i].index = i;
        nodes[i].degree = degree;
        nodes[i].color = 0;
    }

    //排序
    sort(nodes, nodes + m, com);

//    for (int m = 0; m < numOfNodes; ++m) {
//        cout << nodes[m].index << "," << nodes[m].degree << endl;
//    }

    int k = 0;//K 代表第几种颜色
    while (true) {
        k++;
        int i;
        for (i = 0; i < m; i++){//先找到第一个未着色的节点
            if (nodes[i].color == 0) {
                nodes[i].color = k;
                break;
            }
        }
        if (i == m)//循环退出的条件,所有节点都已着色
            break;
        //再把所有不和该节点相邻的节点着相同的颜色
        for(int j=0; j<m; j++){
            if(nodes[j].color ==0 && map[nodes[i].index][nodes[j].index] == 0
               &&i!=j)
                nodes[j].color = k;
        }
    }

    //输出结果：
    sort(nodes, nodes + m, com2);
    cout << "共需要" << k-1 << "种颜色" << endl;
    for (int i = 0; i < m; i++)
        cout<< "节点："<<nodes[i].index <<":着色" << nodes[i].color <<endl;
}

void adjacency2Incidence(vector<vector<int>> _adjacencyMatrix, map<int, map<int, int>> &_incidenceMatrix) {
    int numOfNodes = int(_adjacencyMatrix.size());
    int index = 0;
    int edgeID = 0;
    for (int i = 0; i < numOfNodes; ++i) {
        for (int j = 0; j < index; ++j) {
            if (_adjacencyMatrix[i][j] == 1) {
                _incidenceMatrix[i][edgeID] = 1;
                _incidenceMatrix[j][edgeID] = 1;
                for (int k = 0; k < numOfNodes; ++k) {
                    if (k != i && k != j) {
                        _incidenceMatrix[k][edgeID] = 0;
                    }
                }
                edgeID++;
            }
        }
        index++;
    }

    cout << "incidenceMatrix:" << endl;
    for (int m = 0; m < numOfNodes; ++m) {
        for (int i = 0; i < edgeID; ++i) {
            cout << _incidenceMatrix[m][i] << ",";
        }
        cout << endl;
    }
}

void graghColoringByIncidenceMatrix(map<int, map<int, int>> _incidenceMatrix) {
    int numOfNodes = int(_incidenceMatrix.size());
    int numOfEdge = int(_incidenceMatrix.at(0).size());

    Node nodes[numOfNodes];

    for (int i = 0; i < numOfNodes; i++) {//读入数据 i是节点序号
        int degree = 0;
        for (int j = 0; j < numOfEdge; j++) { //j是边序号
            if (_incidenceMatrix[i][j])
                degree++;
        }
        nodes[i].index = i;
        nodes[i].degree = degree;
        nodes[i].color = 0;
    }

    //排序
    sort(nodes, nodes + numOfNodes, com); //按度从高到低排序

//    for (int m = 0; m < numOfNodes; ++m) {
//        cout << nodes[m].index << "," << nodes[m].degree << endl;
//    }

    int k = 0;//K 代表第几种颜色
    while (true) {
        k++;
        int i;
        for (i = 0; i < numOfNodes; i++){//先找到第一个未着色的节点
            if (nodes[i].color == 0) {
                nodes[i].color = k;
                break;
            }
        }
        if (i == numOfNodes)//循环退出的条件,所有节点都已着色
            break;
        //再把所有不和该节点相邻的节点着相同的颜色
        for(int j = 0; j < numOfNodes; j++){
            if (nodes[j].color == 0) {
                int flag = 0;
                for (int l = 0; l < numOfEdge; ++l) {
                    if(_incidenceMatrix[nodes[i].index][l] == 1 && _incidenceMatrix[nodes[j].index][l] == 1) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    nodes[j].color = k;
                }
            }
        }
    }

    //输出结果：
    sort(nodes, nodes + numOfNodes, com2); //按节点序号从高到低排序
    cout << "共需要" << k - 1 << "种颜色" << endl;
    for (int i = 0; i < numOfNodes; i++){
        cout << "节点：" << nodes[i].index <<":着色" << nodes[i].color <<endl;
    }
}

void graghColoringByIncidenceMatrix(vector<vector<int>> _incidenceMatrix) {
    int numOfNodes = int(_incidenceMatrix.size());
    int numOfEdge = int(_incidenceMatrix.at(0).size());

    Node nodes[numOfNodes];

    for (int i = 0; i < numOfNodes; i++) {//读入数据 i是节点序号
        int degree = 0;
        for (int j = 0; j < numOfEdge; j++) { //j是边序号
            if (_incidenceMatrix[i][j])
                degree++;
        }
        nodes[i].index = i;
        nodes[i].degree = degree;
        nodes[i].color = 0;
    }

    //排序
    sort(nodes, nodes + numOfNodes, com); //按度从高到低排序

    int k = 0;//K 代表第几种颜色
    while (true) {
        k++;
        int i;
        for (i = 0; i < numOfNodes; i++){//先找到第一个未着色的节点
            if (nodes[i].color == 0) {
                nodes[i].color = k;
                break;
            }
        }
        if (i == numOfNodes)//循环退出的条件,所有节点都已着色
            break;
        //再把所有不和该节点相邻的节点着相同的颜色
        for(int j = 0; j < numOfNodes; j++){
            if (nodes[j].color == 0) {
                int flag = 0;
                for (int l = 0; l < numOfEdge; ++l) {
                    if(_incidenceMatrix[nodes[i].index][l] == 1 && _incidenceMatrix[nodes[j].index][l] == 1) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    nodes[j].color = k;
                }
            }
        }
    }

    //输出结果：
    sort(nodes, nodes + numOfNodes, com2); //按节点序号从高到低排序
    cout << "共需要" << k - 1 << "种颜色" << endl;
    for (int i = 0; i < numOfNodes; i++){
        cout << "节点：" << nodes[i].index <<":着色" << nodes[i].color <<endl;
    }
}

void hypergraghColoring(map<int, map<int, int>> _incidenceMatrix) {
    map<int, map<int, int>> subIncidenceMatrix = _incidenceMatrix;
    int numOfColor = 4; //颜色数
    int numOfNodes = int(_incidenceMatrix.size());
    int numOfEdge = int(_incidenceMatrix.at(0).size());
    int colorOrder = numOfNodes;

    Node nodes[numOfNodes];

    for (int i = 0; i < numOfNodes; i++) {//读入数据 i是节点序号
        int degree = 0;
        for (int j = 0; j < numOfEdge; j++) { //j是边序号
            if (_incidenceMatrix[i][j] > 0)
                degree++;
        }
        nodes[i].index = i;
        nodes[i].degree = degree;
        nodes[i].color = 0;
        nodes[i].order = RAND_MAX;
    }

    //排序
    sort(nodes, nodes + numOfNodes, _com); //按度从低到高排序
    nodes[0].order = colorOrder;

    //删除节点 将节点和涉及的边置为-1
    for (int k = 0; k < numOfEdge; ++k) {
        subIncidenceMatrix[nodes[0].index][k] = -1;
        if (_incidenceMatrix[nodes[0].index][k]) {
            for (int i = 0; i < numOfNodes; ++i) {
                subIncidenceMatrix[i][k] = -1;
            }
        }
    }

    cout << "subIncidenceMatrix:" << endl;
    for (int m = 0; m < _incidenceMatrix.size(); ++m) {
        for (int i = 0; i < _incidenceMatrix.at(0).size(); ++i) {
            cout << subIncidenceMatrix[m][i] << ",";
        }
        cout << endl;
    }
    cout << "节点:" << nodes[0].index + 1 << "的着色序号" << nodes[0].order << endl;

    int nodeID = 1;
    do {
        sort(nodes, nodes + numOfNodes, com2); //按节点序号从高到低排序
        colorOrder--;

        for (int i = 0; i < numOfNodes; i++) {//读入数据 i是节点序号
            int degree = 0;
            for (int j = 0; j < numOfEdge; j++) { //j是边序号
                if (subIncidenceMatrix[i][j] > 0)
                    degree++;
            }
            nodes[i].degree = degree;
        }

        //排序
        sort(nodes, nodes + numOfNodes, _com); //按度从低到高排序
        nodes[nodeID].order = colorOrder;
        //删除节点
        //删除节点 将节点和涉及的边置为-1
        for (int k = 0; k < numOfEdge; ++k) {
            subIncidenceMatrix[nodes[nodeID].index][k] = -1;
            if (_incidenceMatrix[nodes[nodeID].index][k]) {
                for (int i = 0; i < numOfNodes; ++i) {
                    subIncidenceMatrix[i][k] = -1;
                }
            }
        }
        cout << "subIncidenceMatrix:" << endl;
        for (int m = 0; m < _incidenceMatrix.size(); ++m) {
            for (int i = 0; i < _incidenceMatrix.at(0).size(); ++i) {
                cout << subIncidenceMatrix[m][i] << ",";
            }
            cout << endl;
        }

        cout << "节点:" << nodes[nodeID].index + 1 << "的着色序号" << nodes[nodeID].order << endl;
        nodeID++;
    } while (colorOrder > 1);

    //排序
    sort(nodes, nodes + numOfNodes, _comOrder); //按order从低到高排序

    for (int l = 0; l < numOfNodes; ++l) {
        cout << "节点：" << nodes[l].index + 1 << " order:" << nodes[l].order << endl;
    }

    int k;//K 代表第几种颜色
//    for (k = 1; k <= numOfColor; k++) {
//        cout << "节点：" << nodes[k - 1].index + 1 << " order:" << nodes[k - 1].order << endl;
//        nodes[k - 1].color = k;
//    }
    for (int i = 0; i < numOfNodes; i++) {
        cout << "节点：" << nodes[i].index + 1 <<":着色" << nodes[i].color << endl;
    }

//    int k = 0;//K 代表第几种颜色
//    while (true) {
//        k++;
//        int i;
//        for (i = 0; i < numOfNodes; i++){//先找到第一个未着色的节点
//            if (nodes[i].color == 0) {
//                nodes[i].color = k;
//                cout << "节点：" << nodes[i].index <<":着色" << nodes[i].color <<endl;
//                break;
//            }
//        }
//        if (i == numOfNodes)//循环退出的条件,所有节点都已着色
//            break;
//        //再把所有不和该节点相邻的节点着相同的颜色
//        for(int j = 0; j < numOfNodes; j++){
//            if (nodes[j].color == 0) {
//                int flag = 0;
//                for (int l = 0; l < numOfEdge; ++l) {
//                    if(_incidenceMatrix[nodes[i].index][l] == 1 && _incidenceMatrix[nodes[j].index][l] == 1) {
//                        flag = 1;
//                    }
//                }
//                if (flag == 0) {
//                    nodes[j].color = k;
//                    cout << "节点：" << nodes[j].index <<":着色" << nodes[j].color <<endl;
//                }
//            }
//        }
//    }
//
//    //输出结果：
//    sort(nodes, nodes + numOfNodes, com2); //按节点序号从高到低排序
//    cout << "共需要" << k - 1 << "种颜色" << endl;
//    for (int i = 0; i < numOfNodes; i++){
//        cout << "节点：" << nodes[i].index <<":着色" << nodes[i].color <<endl;
//    }
}
