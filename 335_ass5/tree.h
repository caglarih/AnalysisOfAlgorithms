/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 5  *
 ********************/

#ifndef TREE_H
#define TREE_H
#include "treenode.h"

class tree{
    treenode* head;
    int count_for_nth;
    std::string found_name;
    int row;
    std::string prepare_print[20];
public:
    tree();
    void insert(Person);
    void print();
    treenode* temp;
    void checkRB(treenode*);
    void rightRotate(treenode*);
    void leftRotate(treenode*);
    void inorder(treenode*,int);
    treenode* getHead();
    std::string nth_woman(int);
    std::string nth_man(int);
    void count(treenode*,char,int);
    int count2(treenode*,char,int);
    void adjustNumbers();
};

#endif // TREE_H
