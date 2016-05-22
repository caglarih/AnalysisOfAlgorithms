/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 1
*/

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include"adjacency.h"


Adjacency::Adjacency(const std::string f){
    std::ifstream file;
    file.open(f.c_str());
    int linecount = 0,curr;
    std::string line = "";
    if(file.is_open()){
        while(getline(file,line)){
            linecount++;
        }
        this->size = linecount;
        file.close();
    }
    file.open(f.c_str());
    if(file.is_open()){
        for(int i = 0;i<linecount;i++){
            this->matrix.push_back(std::vector<int>(0,1));
            for(int j = 0; j< linecount; j++){
                file >> curr;
                this->matrix[i].push_back(curr);
            }
        }
        file.close();
    }
}

Adjacency::Adjacency(const Adjacency& in){
    this->size = in.getSize();
    this->matrix = in.getMatrix();
}

bool Adjacency::getConnection(int i,int j) const {
    return (this->matrix[i][j]==1);
}
