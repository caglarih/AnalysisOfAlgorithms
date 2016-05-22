/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 2
*/
#include "sequence.h"

using namespace std;

void Sequence::fillSeq(string f){
    ifstream file;
    file.open(f.c_str());
    string line = "";
    if(file.is_open()){
        getline(file,line);
        while(getline(file,line)){
            this->seq.append(line);
        }
        file.close();
    }
}

int Sequence::getLength(){
    return this->seq.length();
}
