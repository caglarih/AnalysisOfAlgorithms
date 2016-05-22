/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 4  *
 ********************/


#ifndef HASHTABLE_H
#define HASHTABLE_H

class Table{
    int* data;
    int length;
    int collision;
    int deleted;
public:
    void create(int);
    int get_collision();
    int add(int,int);
    bool del(int,int);
    int ret(int,int);
    Table();
    ~Table();
    int maxcol;
};

#endif // HASHTABLE_H

