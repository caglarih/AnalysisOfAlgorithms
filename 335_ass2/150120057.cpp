/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 2  *
 ********************/


#include <iostream>
#include <sstream>
#include <time.h>
#include <string>
#include "scorelist.h"
using namespace std;

int main( int argc, char *argv[] )
{
    scorelist sc = scorelist();
    int line,k,index;
    istringstream (argv[1]) >> line;
    sc.create(line);
    istringstream (argv[2]) >> k;
    clock_t s = clock();
    index = sc.find_applicant(k);
    clock_t e = clock();
    sc.print_sc();
    sc.print_fl(e-s);
    cout << "Clock: " << e-s << endl;
    return 0;
}

