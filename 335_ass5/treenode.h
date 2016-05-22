/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 5  *
 ********************/

#ifndef TREENODE_H
#define TREENODE_H

#include "person.h"
enum Color{
    RED,BLACK
};

class treenode{
public:
    Person person;
    treenode* left;
    treenode* right;
    treenode* parent;
    Color color;
    treenode();
    int num_woman;
    int num_man;
};

#endif // TREENODE_H
