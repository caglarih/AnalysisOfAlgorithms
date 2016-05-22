/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 1
*/
#ifndef ADJACENCY_H
#define ADJACENCY_H

#include<vector>
#include<algorithm>
#include<iostream>

enum Points{
    A,B,C,D,E,F,G
};

class Adjacency{
    std::vector<std::vector<int> > matrix;
    int size;
public:
    Adjacency(){size=0;}
    Adjacency(std::string);
    Adjacency(const Adjacency&);
    ~Adjacency(){}
    int getSize() const {return size;}
    std::vector<std::vector<int> > getMatrix() const {return matrix;}
    bool getConnection(int,int) const;
};

#endif // ADJACENCY_H
