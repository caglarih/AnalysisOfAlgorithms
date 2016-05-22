/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 2
*/
#ifndef NEEDLEMAN_H
#define NEEDLEMAN_H
#include "sequence.h"

class Needleman{
    Scores sc;
    std::string seq1;
    std::string seq2;
    int len1,len2;
    std::vector<std::vector<int> > matrix;
    int score;
public:
    void initialize(Scores,Sequence,Sequence);
    void fill();
    void traceback();
};

#endif // NEEDLEMAN_H
