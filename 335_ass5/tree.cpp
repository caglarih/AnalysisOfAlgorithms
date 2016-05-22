/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 5  *
 ********************/

#include "tree.h"
#include <iostream>
#include <sstream>
tree::tree(){
    head = NULL;
    count_for_nth = 0;
    found_name = "";
    row = 0;
}

void tree::print(){
    for(int i = 0;i<20;i++) prepare_print[i] = "";
    row = 0;
    this->inorder(head,0);
    for(int i = 0;i<6;i++){
        bool count = false;
        for(int j = 0;j<20;j++){
            if(prepare_print[j][4*i] == '|'){
                if(prepare_print[j][4*i+1] == '-'){
                    count = !count;
                }
            }
            if(!count){
                if(prepare_print[j][4*i] == '|'){
                    if(prepare_print[j][4*i+1] != '-') prepare_print[j][4*i] =  ' ';
                }
            }
        }
    }
    for(int i = 0;i<20;i++) std::cout << prepare_print[i];
}

std::string tree::nth_man(int i){
    count_for_nth = 0;
    found_name = "";
    this->count(head,'M',i);
    return found_name;
}

std::string tree::nth_woman(int i){
    count_for_nth = 0;
    found_name = "";
    this->count(head,'F',i);
    return found_name;
}

void tree::count(treenode* a,char c, int i){
    if(a==NULL){
        return;
    }
    count(a->left,c,i);
    if(a->person.getGender() == c){
        count_for_nth++;
        if(count_for_nth == i){
            found_name = a->person.getName();
            count_for_nth++;
        }
    }
    count(a->right,c,i);
}

void tree::adjustNumbers(){
    this->count2(head,'F',0);
    this->count2(head,'M',0);
}

int tree::count2(treenode* a,char c ,int i){
    if(a==NULL){
        return 0;
    }
    int t,y;
    t=count2(a->left,c,i);
    if(a->person.getGender() == c){
        t++;
    }
    y=count2(a->right,c,i);
    i = i+y+t;
    if(c=='F') a->num_woman = i;
    else if(c=='M') a->num_man = i;
    return i;
}

void tree::insert(Person p){
    int i = 0;
    if(head == NULL){
        head = new treenode();
        head->color = BLACK;
        head->person = p;
    }
    else{
        temp = head;
        treenode* parent;
        while(temp != NULL){
            if(temp->person.getAge()>p.getAge()){
                parent = temp;
                temp = temp->left;
                i=1;
            }
            else if(temp->person.getAge()<p.getAge()){
                parent = temp;
                temp = temp->right;
                i=2;
            }
        }
        temp = new treenode();
        if(i==1) parent->left = temp;
        else if(i==2) parent->right = temp;
        temp->person = p;
        temp->parent = parent;
        temp->color = RED;
        this->checkRB(temp);
        this->adjustNumbers();
    }
}
void tree::checkRB(treenode * pt){
    treenode *parent = NULL;
    treenode *gp = NULL;
    while ((pt != head) && (pt->color != BLACK) && (pt->parent->color == RED)) {
            bool cont = true;
            parent = pt->parent;
            gp = pt->parent->parent;
            treenode* uncle = NULL;
            if (parent == gp->left) {
                uncle = gp->right;
                if(!((uncle != NULL) && (uncle->color == RED))) {
                    if (pt == parent->right) {
                        this->leftRotate( parent);
                        pt = parent;
                        parent = pt->parent;
                    }
                    this->rightRotate(gp);
                    Color a = parent->color;
                    parent->color = gp->color;
                    gp->color = a;
                    pt = parent;
                    cont = false;
                }
            }
            else {
                uncle = gp->left;
                if(!((uncle != NULL) && (uncle->color == RED))) {
                    if (pt == parent->left) {
                        this->rightRotate(parent);
                        pt = parent;
                        parent = pt->parent;
                    }
                    this->leftRotate(gp);
                    Color a = parent->color;
                    parent->color = gp->color;
                    gp->color = a;
                    pt = parent;
                    cont = false;
                }
            }
            if(cont){
                gp->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                pt = gp;
            }
        }
        head->color = BLACK;
}

void tree::leftRotate(treenode * x){
    treenode* y = x->right;
    x->right = y->left;
    if(x->right!=NULL){
        x->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent==NULL){
        head = y;
    }
    else if(x==x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void tree::rightRotate(treenode * y){
    treenode* x = y->left;
    y->left = x->right;
    if(y->left!=NULL){
        y->left->parent = y;
    }
    x->parent = y->parent;
    if(y->parent == NULL){
        head = x;
    }
    else if(y == y->parent->left){
        y->parent->left = x;
    }
    else{
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void tree::inorder(treenode* a,int h){
    if(a==NULL){
        return;
    }
    h+=4;
    //std::cout << "[";
    inorder(a->left,h);
    h-= 4;
    for(int i = 0;i<h;i++){
        if(i%4==0) prepare_print[row].append("|");
        else prepare_print[row].append(" ");
    }
    std::stringstream ss;
    ss << a->person.getAge();
    prepare_print[row].append("|--").append(a->person.getName()).append("-").append(ss.str());
    prepare_print[row].append("-").push_back(a->person.getGender());
    prepare_print[row].append("\n");
    row++;
    inorder(a->right,h+4);
}

treenode* tree::getHead(){
    return head;
}
