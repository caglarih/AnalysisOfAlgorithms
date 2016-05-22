/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 4  *
 ********************/


#include <iostream>
#include <fstream>
#include <hashtable.h>
#include <sstream>
using namespace std;

int main()
{
    string line;
    string data[4000];
    ifstream fil;
    Table t1 = Table();
    Table t2 = Table();
    Table t3 = Table();
    int curr = 0,ret;
    bool ret2;
    t1.create(2477);
    t2.create(2477);
    t3.create(2477);
    fil.open("dataset.txt");
    if(fil.is_open()){
        for(int i=0;i<3139;i++){
           getline(fil,line);
           data[i] = line;
        }
    }
    fil.close();
    for(int i = 0;i<3139;i++){
        line = data[i];
        if(line[0]=='i'){
            try{
                string a = line.substr(7);
                stringstream ss(a);
                ss>> curr;
            }
            catch(int e){
                cerr << "error" << endl;
            }
            ret = t1.add(1,curr);
            cout << "Insertion: Key " << curr << " is inserted in index " << ret <<" to table 1." << endl;
            ret = t2.add(2,curr);
            cout << "Insertion: Key " << curr << " is inserted in index " << ret <<" to table 2." << endl;
            ret = t3.add(3,curr);
            cout << "Insertion: Key " << curr << " is inserted in index " << ret <<" to table 3." << endl;
        }
        else if(line[0]=='d'){
            stringstream(line.substr(7,7)) >> curr;
            ret2 = t1.del(1,curr);
            if(ret2) cout << "Deletion: Key " << curr << " is deleted from the table 1." << endl;
            else cout << "Deletion: Key " << curr << " is not found in the table 1." << endl;
            ret2 = t2.del(2,curr);
            if(ret2) cout << "Deletion: Key " << curr << " is deleted from the table 2." << endl;
            else cout << "Deletion: Key " << curr << " is not found in the table 2." << endl;
            ret2 = t3.del(3,curr);
            if(ret2) cout << "Deletion: Key " << curr << " is deleted from the table 3." << endl;
            else cout << "Deletion: Key " << curr << " is not found in the table 3." << endl;
        }
        else if(line[0]=='r'){
            stringstream(line.substr(9,7)) >> curr;
            ret = t1.ret(1,curr);
            if(ret!=-1) cout << "Retrieve: Key " << curr << " is found at index " << ret <<" in table 1." << endl;
            else cout << "Retrieve: Key " << curr << " is not found in the table 1." << endl;
            ret = t2.ret(2,curr);
            if(ret!=-1) cout << "Retrieve: Key " << curr << " is found at index " << ret <<" in table 2." << endl;
            else cout << "Retrieve: Key " << curr << " is not found in the table 2." << endl;
            ret = t3.ret(3,curr);
            if(ret!=-1) cout << "Retrieve: Key " << curr << " is found at index " << ret <<" in table 3." << endl;
            else cout << "Retrieve: Key " << curr << " is not found in the table 3." << endl;
        }
        //istringstream(line) >> curr;
        //data[i] = curr;

    }
    cout << "Collisions on linear hashing: " << t1.get_collision() << endl;
    cout << "Collisions on double hashing: " << t2.get_collision() << endl;
    cout << "Collisions on quadratic hashing: " << t3.get_collision() << endl;
    cout << t2.maxcol;
    ret = 0;
    return ret;
}

