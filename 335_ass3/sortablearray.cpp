#include "sortablearray.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

void merge_sort(int[],int, int);
void merge(int[],int,int,int);
void quick_sort(int[],int,int,int);
int partition(int[],int,int,int);

bool sortableArray::sort_counting(int d){
    int n, max = 0,temp[length+1], t;
    int* counts = NULL;
    if(d<1){
        n = length;
        for(int i = 1;i<length;i++){
            if(max<data[i]) max = data[i];
        }
    }
    else{
        n=length;
        max = 10;
    }
    counts = new int[max+1];
    if(counts != NULL){
        for(int i = 0; i<max+1;i++) counts[i] = 0;

        for(int i = 1; i<= length;i++){
            t = data[i];
            for(int j = 2;j<d;j++){
                t /= 10;
            }
            if(d>0) t = t%10;
            counts[t] += 1;
        }
        for(int i = 1;i<=max;i++) counts[i] += counts[i-1];
        for(int i = n;i>=1;i--){
            t = data[i];
            for(int j = 2;j<d;j++){
                t /= 10;
            }
            if(d>0) t = t%10;
            temp[counts[t]] = data[i];
            counts[t] -= 1;
        }
        for(int i = 1;i<length+1;i++){
            data[i] = temp[i];
        }
        delete[] counts;
    }
    else return false;
}

void sortableArray::sort_quick(){
   quick_sort(data,1,length-1,0);
}

void sortableArray::sort_radix(){
    int max = 0;
    int d = 0;
    bool a;
    for(int i = 1;i<length;i++){
        if(max<data[i]) max = data[i];
    }
    while(max!=0){
        max /= 10;
        d++;
    }
    for(int i=1;i<=d;i++){
        a = this->sort_counting(i+1);
    }
}

bool sortableArray::create(int l,const char* address){
    length = l;
    data = new int[l];
    int curr;
    string line;
    ifstream file;
    data = new int[l];
    file.open(address);
    if(file.is_open()){
        for(int i=1;i<l;i++){
            getline(file,line);
            istringstream(line) >> curr;
            data[i] = curr;
        }
    }
    else return false;
    file.close();
    return true;
}


void sortableArray::print_screen(){
    for(int i = 1; i<length;i++) cout << i << ". " <<  data[i] << endl;
}


bool sortableArray::print_txt(){
    ofstream out;
    out.open("sorted.txt");
    if(out.is_open()){
        for(int i = 1;i<length;i++){
            out << data[i] << "\n";
        }
    }
    else return false;
    out.close();
    return true;
}

sortableArray::sortableArray(){
    length = 0;
    data = NULL;
}

sortableArray::~sortableArray(){
    delete [] data;
}


void quick_sort(int arr[], int f, int l, int d){
    if(f<l){
        int boundary = partition(arr,f,l,d);
        quick_sort(arr,f,boundary-1,d);
        quick_sort(arr,boundary+1,l,d);
    }
}

int partition(int arr[],int f,int l ,int d){
    int pivot = arr[l];
    int boundary = f,temp = 0;
    int pivot_d,arr_d;
    bool cond=false;
    for(int i = f;i<l;i++){
        if(d < 1){
            if(arr[i]<pivot){
                cond = true;
            }
        }
        else{
            pivot_d = pivot;
            arr_d = arr[i];
            for(int j=1;j!=d;j++){
                pivot_d /= 10;
                arr_d /= 10;
            }
            if(arr_d%10 < pivot_d%10){
                cond = true;
            }
        }
        if(cond){
            temp = arr[i];
            arr[i] = arr[boundary];
            arr[boundary] = temp;
            boundary+=1;
        }
        cond = false;
    }
    temp = arr[boundary];
    arr[boundary] = arr[l];
    arr[l] = temp;
    return boundary;
}

