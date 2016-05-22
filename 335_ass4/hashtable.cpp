/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 4  *
 ********************/


#include "hashtable.h"
#include <iostream>

using namespace std;

int hf1(int,int,int);
int hf2(int,int,int);
int hf3(int,int,int);

int Table::ret(int met,int id){
    bool found = false,notfound=false;
    int i = 0, ret = -1;
    while(!found && !notfound){
        if(met == 1){
           ret = hf1(id,i,length);
           if(data[ret] == id) found = true;
           else i++;
        }
        else if(met == 2){
           ret = hf2(id,i,length);
           if(data[ret] == id) found = true;
           else i++;
        }
        else if(met == 3){
           ret = hf3(id,i,length);
           if(data[ret] == id) found = true;
           else i++;
        }
        if(data[ret] == 0) notfound = true;
    }
    if(!notfound){
        return ret;
    }
    else{
        return -1;
    }
}

bool Table::del(int met,int id){
    bool found = false,notfound=false;
    int i = 0, ret = -1;
    int * temp;
    while(!found && !notfound){
        if(met == 1){
           ret = hf1(id,i,length);
           if(data[ret] == id) found = true;
           else i++;
        }
        else if(met == 2){
           ret = hf2(id,i,length);
           if(data[ret] == id) found = true;
           else i++;
        }
        else if(met == 3){
           ret = hf3(id,i,length);
           if(data[ret] == id) found = true;
           else i++;
        }
        if(data[ret] == 0) notfound = true;
    }
    if(!notfound){
        deleted++;
        data[ret] = -1;
        if(deleted==50){
            temp = new int[2477];
            for(int i = 0;i<2477;i++){
                if(data[i]>0){
                    bool fnd = false;
                    int cur = data[i];
                    int j = 0, ret2 = -1;
                    while(!fnd){
                        if(met == 1){
                           ret2 = hf1(cur,j,length);
                           if(temp[ret2]==0) fnd = true;
                           else j++;
                        }
                        else if(met == 2){
                           ret2 = hf2(cur,j,length);
                           if(temp[ret2]==0) fnd = true;
                           else j++;
                        }
                        else if(met == 3){
                           ret2 = hf3(cur,j,length);
                           if(temp[ret2]==0) fnd = true;
                           else j++;
                        }
                    }
                    //collision+=j;
                    temp[ret] = cur;
                }
            }
            delete[] data;
            data = temp;
            deleted = 0;
        }
        return true;
    }
    else{
        return false;
    }
}

int Table::add(int met , int id){
    bool found = false;
    int i = 0, ret = -1;
    while(!found){
        if(met == 1){
           ret = hf1(id,i,length);
           if(data[ret]==0 || data[ret]== -1) found = true;
           else i++;
        }
        else if(met == 2){
           ret = hf2(id,i,length);
           if(data[ret]==0 || data[ret]== -1) found = true;
           else i++;
        }
        else if(met == 3){
           ret = hf3(id,i,length);
           if(data[ret]==0 || data[ret]== -1) found = true;
           else i++;
        }
    }
    if(data[ret]==-1) deleted--;
    collision+=i;
    data[ret] = id;
    return ret;
}

void Table::create(int l){
    length = l;
    data = new int[l+1];
    for(int i =0;i<length;i++) data[i] = 0;
}

int Table::get_collision(){
    return collision;
}

Table::Table(){
    data = NULL;
    length = 0;
    deleted = 0;
    collision = 0;
    maxcol = 0;
}

Table::~Table(){
    delete[] data;
}


int hf1(int k, int i, int m){
    int r = (k+i)%m;
    return r;
}

int hf2(int k, int i, int m){
    int r = ((k%m) + i* (1+k%(m-4)))%m;
    return r;
}

int hf3(int k, int i, int m){
    int r = (k%m + i+ 2*i*i)%m;
    return r;
}
