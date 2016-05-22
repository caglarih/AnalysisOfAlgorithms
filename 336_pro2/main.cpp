/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 2
*/
#include <iostream>
#include "needleman.h"

using namespace std;

int main()
{
    Scores s = Scores();
    s.fillScores("BLOSUM62.txt");
    Sequence s1 = Sequence();
    s1.fillSeq("human-hemoglobin-sequence.fasta");
    Sequence s2 = Sequence();
    s2.fillSeq("mouse-hemoglobin-sequence.fasta");
    Needleman n = Needleman();
    n.initialize(s,s1,s2);
    n.fill();
    n.traceback();
    return 0;
}
