/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 2  *
 ********************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "scorelist.h"
using namespace std;

scorelist::scorelist(){
    data = NULL;
}

scorelist::~scorelist(){
    delete []data;
}

void scorelist::create(int line_no){
    data = new int[10];
    ifstream file;
    file.open("data.txt");
    string line;
    int curr=0;
    if(file.is_open()){
        for(int i =0;i<line_no;i++){
            getline(file,line);
        }
        for(int i =0;i<10;i++){
            istringstream (line) >> curr;
            data[i] = curr;
            if(i!=9)line = line.substr(3);
        }
    }
    else cout << "Error..." << endl;
}

int scorelist::find_applicant(int k){
    int max=-20;
    for(int i=0;i<k;i++){
        if(data[i]>max) max=data[i];
    }
    for(int i=k;i<10;i++){
        if(data[i]>max){
            selected = i;
            return i;
        }
    }
    selected = 9;
    return 9;
}

void scorelist::print_sc(){
    cout << "Applicant Index: " << selected << endl;
    cout << "Applicant Score: " << data[selected] << endl;
}

void scorelist::print_fl(int r){
    ofstream out;
    out.open("best_applicant.txt");
    if(out.is_open()){
        out << selected << "\n";
        out << data[selected] << "\n";
        out << r << "\n";
        cout << "Printing te ile " << selected +data[selected]+r << endl;
    }
    else cout << "Error.." << endl;
    out.close();
}
