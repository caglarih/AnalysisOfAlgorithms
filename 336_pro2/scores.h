/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 2
*/
#ifndef SCORES_H
#define SCORES_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>

class Scores{
    std::vector<std::vector<int> >martix;
    std::map<char,int> letters;
    int length;
public:
    Scores();
    int getScore(char,char);
    void fillScores(std::string);
    int getLength(){return length;}
};

#endif // SCORES_H
