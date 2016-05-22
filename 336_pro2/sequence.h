/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 2
*/
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "scores.h"

class Sequence{
    std::string seq;
public:
    std::string getSeq(){return seq;}
    void fillSeq(std::string);
    int getLength();
};

#endif // SEQUENCE_H
