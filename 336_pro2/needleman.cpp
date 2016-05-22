/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 2
*/
#include "needleman.h"
using namespace std;

void Needleman::initialize(Scores scrs, Sequence s1, Sequence s2){
    this->seq1 = s1.getSeq();
    this->seq2 = s2.getSeq();
    this->len1 = s1.getLength();
    this->len2 = s2.getLength();
    this->sc = scrs;
    vector<int> temp(len2+1,0);
    for(int i = 0;i<len1+1;i++){
        this->matrix.push_back(temp);
    }
    for(int i = 0;i<len1+1;i++){
        this->matrix[i][0] = i*sc.getScore(this->seq1[i],'*');
    }
    for(int i = 0;i<len2+1;i++){
        this->matrix[0][i] = i*sc.getScore(this->seq2[i],'*');
    }
}

void Needleman::fill(){
    int c1,c2,c3;
    for(int i = 1;i<len1+1;i++){
        for(int j = 1;j<len2+1;j++){
            c1 = this->sc.getScore(this->seq1[i-1],this->seq2[j-1]);
            c1 = this->matrix[i-1][j-1] + c1;
            c2 = this->matrix[i][j-1] + sc.getScore(this->seq1[i-1],'*');
            c3 = this->matrix[i-1][j] + sc.getScore(this->seq2[j-1],'*');
            if(c1>=c2 && c1>=c3) this->matrix[i][j] = c1;
            else if(c2>=c3) this->matrix[i][j] = c2;
            else this->matrix[i][j] = c3;
        }
    }
    this->score = this->matrix[len1][len2];
}

void Needleman::traceback(){
    int i=this->len1,j=this->len2;
    int len=0,identity = 0,similarity=0,gap=0;
    string r1 = "",r2 = "",r3 = "";
    while(i>0 || j>0){
        if(seq1[i-1]==seq2[j-1]){
            identity++;
            r2 = '|' + r2;
        }
        else if(sc.getScore(seq1[i-1],seq2[j-1])>=0){
            similarity++;
            r2 = ':' + r2;
        }
        else{
            r2 = '.'+ r2;
        }
        if(i>0 && j>0 && matrix[i][j]==matrix[i-1][j-1]+sc.getScore(seq1[i-1],seq2[j-1])){
            r1 = seq1[i-1] + r1;
            r3 = seq2[j-1] + r3;
            i -= 1;
            j -= 1;
        }
        else if(i>0 && matrix[i][j]==matrix[i-1][j]+sc.getScore(seq1[i-1],'*')) {
            r1 = seq1[i-1] + r1;
            r3 = '-' + r3;
            i -= 1;
            gap++;
            r2[0] = ' ';
        }
        else{
            r3 = seq2[j-1] + r3;
            r1 = '-' + r1;
            j -= 1;
            gap++;
            r2[0] = ' ';
        }
        len++;
    }
    cout << "#########################################################################" << endl;
    cout << "#\t\t\t\t\t\t\t\t\t#" << endl;
    cout << "# Length:     "; cout.width(9);  cout << right << len << " (with gaps)\t\t\t\t\t#" << endl;
    cout << "# Identity:   "; cout.width(5);  cout << right << identity << "/" << len << " (|)\t\t\t\t\t\t#" << endl;
    cout << "# Similarity: "; cout.width(5);  cout << right << similarity+identity << "/" << len << " (| and :)\t\t\t\t\t#" << endl;
    cout << "# Score:      "; cout.width(9);  cout << right << this->score << "\t\t\t\t\t\t\t#" << endl;
    cout << "# Gaps:       "; cout.width(9);  cout << right << gap << "\t\t\t\t\t\t\t#" << endl;
    cout << "#\t\t\t\t\t\t\t\t\t#" << endl;
    cout << "#=======================================================================#" << endl;
    cout << "#\t\t\t\t\t\t\t\t\t#" << endl;
    for(int i = 0;i<len;i+=50){
        cout << "# human  "; cout.width(5);  cout << right << i+1 << "  " << r1.substr(i,50)+" " << i+50 << "\t#" << endl;
        cout << "#        "; cout.width(5);  cout << right << i+1 << "  " << r2.substr(i,50)+" " << i+50 << "\t#" << endl;
        cout << "# mouse  "; cout.width(5);  cout << right << i+1 << "  " << r3.substr(i,50)+" " << i+50 << "\t#" << endl;
        cout << "#\t\t\t\t\t\t\t\t\t#" << endl;
    }
    cout << "#########################################################################" << endl << endl;
}
