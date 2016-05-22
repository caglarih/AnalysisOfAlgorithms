/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 5  *
 ********************/

#include <iostream>
#include <fstream>
#include <sstream>
#include "tree.h"
using namespace std;

void usage(){
    cout << "Usage: " << endl;
}

int main(int argc,char** argv)
{
    ifstream file;
    string line,name,gender,temp;
    int age;
    tree t;
    if(argc<2 || argc > 3){
        usage();
    }
    else{
        file.open(argv[1]);
        if(file.is_open()){
            for(int i = 0;i<20;i++){
                getline(file,line);
                name = line.substr(0,line.find('\t'));
                temp = line.substr(line.find('\t')+1);
                gender =  temp[0];
                temp = temp.substr(temp.find('\t')+1);
                istringstream(temp) >> age;
                Person p = Person(age,name,gender[0]);
                t.insert(p);
                cout << name << "   " << gender << "   " << age << " is added" << endl;
            }
        }
        file.close();
        cout << endl;
        t.print();
        cout << endl << endl;
        cout << "2. youngest man: " << t.nth_man(2) << endl;
        cout << "8. youngest woman: " << t.nth_woman(8) << endl;
    }
    return 0;
}
