/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 2
*/
#include "scores.h"
using namespace std;

Scores::Scores(){

}
void Scores::fillScores(string f){
    ifstream file;
    file.open(f.c_str());
    int curr,first;
    char head;
    string line = "";
    if(file.is_open()){
        getline(file,line);
        while(line[0]=='#'){
            getline(file,line);
        }
        int offset = 0;
        for(int t = 0;t<line.length();t++){
            if(line[t]!=' '){
                letters[line[t]] = offset;
                offset++;
            }
        }
        this->length = offset;
        for(int i = 0;i<offset;i++){
            file >> head;
            first = letters[head];
            vector<int> temp;
            for(int j=0;j<offset;j++){
                file >> curr;
                temp.push_back(curr);
            }
            this->martix.push_back(temp);
            getline(file,line);
        }
        file.close();
    }
}

int Scores::getScore(char a, char b){
    return this->martix[letters[a]][letters[b]];
}
