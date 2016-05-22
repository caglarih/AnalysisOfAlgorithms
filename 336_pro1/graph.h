/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 1
*/
#ifndef GRAPH_H
#define GRAPH_H
#include"adjacency.h"

class Graph{
    Adjacency ad;
    int total;
public:
    int getShortestCount(Points,Points,int*);
    int getBetweeness(Points,Points);
    bool isStrongly();
    Graph(const Adjacency&);
    ~Graph(){}
};

#endif // GRAPH_H
