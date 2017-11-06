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

bool com2(Node node1,Node node2) { //按度从高到低排序
    return node1.index < node2.index;
}

void graghColoringByAdjacencyMatrix(vector<vector<int>> map) {
    Node nodes[8];

    int m = 8;
    int n = 8;
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
            if(nodes[j].color ==0 &&map[nodes[i].index][nodes[j].index] == 0
               &&i!=j)
                nodes[j].color = k;
        }
    }

    //输出结果：
    sort(nodes,nodes + m, com2);
    cout << "共需要" << k-1 << "种颜色" << endl;
    for (int i = 0; i < m; i++)
        cout<< "节点："<<nodes[i].index <<":着色" << nodes[i].color <<endl;
}
