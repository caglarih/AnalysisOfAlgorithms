/*
 * Ihsan Burak Caglar
 * 150120057
 * BLG336E - Analysis of Algorithms II
 * Project 1
*/
#include"graph.h"

using namespace std;

Graph::Graph(const Adjacency& in){
    this->ad = Adjacency(in);
}

int Graph::getShortestCount(Points src,Points dst,int* betweeness){
    bool discovered[ad.getSize()];
    bool discoveredStep[ad.getSize()];
    for(int i =0;i<ad.getSize();i++){
        discovered[i] = false;
        discoveredStep[i] = false;
    }
    int layer = 0,lastOfPath,count=0;
    bool found = false;
    vector<vector<int> > tree;                                  //paths
    tree.push_back(vector<int>(1,int(src)));                    //initialization of the first path with starting point
    discovered[int(src)] = true;                                //starting point is discovered
    while(!found && layer<ad.getSize()){                        //found=finish is reached
        for(int i = 0;i<ad.getSize();i++){                      //lasts step's discovered nodes are added
            discovered[i] = discovered[i]||discoveredStep[i];
            discoveredStep[i] = false;
        }
        int treeSize = tree.size();                             //number of paths are increasing in the loop
        for(int pathNo = 0;pathNo<treeSize;pathNo++){           //treeSize shows the iteration's beginning path count
            if(int(tree[pathNo].size())<=layer) continue;
            lastOfPath = tree[pathNo][layer];
            for(int option = 0;option<ad.getSize();option++){   //checking possible nodes
                if(discovered[option]){}
                else{                                           //not discovered
                    if(ad.getConnection(option,lastOfPath)){    //option is connected to the last node
                        if(option==int(dst)){                   //destination reached
                            found = true;
                            count++;
                        }
                        if(int(tree[pathNo].size()-1)>layer){   //an element is added in this iteration
                            tree.push_back(tree[pathNo]);       //copy the path
                            int index = tree[pathNo].size()-1;  //last node's index(actually it is equal to layer-1)
                            tree[tree.size()-1][index] = option;//change the last node
                        }
                        else{
                            tree[pathNo].push_back(option);     //the path is available to add a new node
                        }
                        discoveredStep[option] = true;          //node is added, mark as discovered
                    }
                }
            }
        }
        layer++;                                                //layer, lengths of the paths
    }
    if(betweeness!=NULL){             //this is a betweeness part
        count = 0;
        int z = tree.size();
        for(int i = 0;i<z;i++){
            if(find(tree[i].begin(), tree[i].end(), int(dst)) != tree[i].end() ){           //the path is true
                if(find(tree[i].begin(), tree[i].end(), betweeness[0]) != tree[i].end() ){      //the path includes small betweeness points
                    if(find(tree[i].begin(), tree[i].end(), betweeness[1]) != tree[i].end() )   //the path is in betweeness
                        count++;
                }
            }
        }
    }
    return count;
}

int Graph::getBetweeness(Points e1, Points e2){
    int total = 0;
    int arr[2];             //given edge will be contained
    arr[0] = int(e1);
    arr[1] = int(e2);
    for(int i = 0;i<ad.getSize()-1;i++){
        for(int j = i+1;j<ad.getSize();j++){
            total += getShortestCount(Points(i),Points(j),arr);
        }
    }
    return total;
}

bool Graph::isStrongly(){
    for(int i = 1;i<ad.getSize()-1;i++){ // the first one should reach other points, and should be reachable for all points
        if(this->getShortestCount(Points(0),Points(i),NULL)<1 || this->getShortestCount(Points(ad.getSize()-i),Points(0),NULL)) return false;
    }
    return true;
}
