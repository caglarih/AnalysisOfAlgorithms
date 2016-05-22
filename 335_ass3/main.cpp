#include <iostream>
#include "sortablearray.h"
#include <time.h>

void help();

using namespace std;

int main(int argc, char* argv[])
{
    string data = "data/";
    int n;
    clock_t s,f;
    bool c_res = true;
    if ( argc != 3 ){
        help();
        c_res = false;
    }
    else{
        data.append(argv[2]);
        sortableArray arr = sortableArray();
        if(argv[2][1]=='0') n = 100000;
        else if(argv[2][1]=='k') n = 1000;
        arr.create(n+1,data.c_str());
        s = clock();
        if(string(argv[1]) == "q"){
            arr.sort_quick();
            cout << "quick" << endl;
        }
        else if(string(argv[1]) == "c"){
            c_res = arr.sort_counting(0);
            if(c_res == false){
                cout << "An error occured while creatig counting array.." << endl;
            }
        }
        else if(string(argv[1]) == "r"){
            arr.sort_radix();
        }
        else help();
        f = clock();
        //arr.print_screen();
        if(c_res != false) arr.print_txt();
    }
    if(c_res != false) cout << "Time cycle: " << f-s << endl;
    if(c_res != false) cout << "Output can be seen in sorted.txt" << endl;
    return 0;
}

void help(){
    cout << endl << "Usage" << endl;
    cout << "   ./150120057 <method> <path-to-file>" << endl;
    cout << endl << "  Specify a file and a method, then see the sorted.txt file." << endl;
    cout << endl << endl;
}
