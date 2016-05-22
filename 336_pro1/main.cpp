/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 1
*/
#include <iostream>
#include "graph.h"

using namespace std;

char nodes[] = {'A','B','C','D','E','F','G'};

int main()
{
    Adjacency adj = Adjacency("input1.txt");
    Graph g = Graph(adj);
    int a[3][2]={
        {0,5},          //A and F
        {4,6},          //pairs that are given in part a
        {1,5}           //B and F
    };
    for(int i = 0;i<3;i++){
        cout << "The number of shortest path(s) from " << nodes[a[i][0]] << " to " << nodes[a[i][1]] << " is: ";
        cout << g.getShortestCount(Points(a[i][0]),Points(a[i][1]),NULL) << endl;
    }
    cout << endl;
    for(int i = 0;i<adj.getSize()-1;i++){
        for(int j = i+1;j<adj.getSize();j++){   //all pair of nodes, check for conenction and calculate the betweeness
            if(adj.getConnection(i,j)){
                cout << "Betweeness of edge " << nodes[i] << "-" << nodes[j] << " is: ";
                cout << g.getBetweeness(Points(i),Points(j)) << endl;
            }
        }
    }
    cout << endl;
    Adjacency adj2 = Adjacency("input2.txt");
    Graph g2 = Graph(adj2);
    bool stronglyConnected = g2.isStrongly();
    if(stronglyConnected){
        cout << "The given directed graph is strongly connected." << endl << endl;
    }
    else{
        cout << "The given directed graph is not strongly connected." << endl << endl;
    }
    return 0;
}
