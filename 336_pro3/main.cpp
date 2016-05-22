/*
 * BLG336E - Analysis of Algorithms II
 *
 * Ihsan Burak Caglar
 * 150120057
 * Project 3
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;

class Graph{
    vector<vector<int> > matrix;
    vector<vector<int> > resMatrix;
    vector<int> result;
    int maxflow;
    int numRobot;
    int numObject;
    vector<int> parent;

public:
    bool bfSearch(int , int);
    void fillMatrix(string);
    void calculate();
    void writeResults();
};

void Graph::fillMatrix(string f){
    ifstream file;
    int curr =0;
    file.open(f.c_str());
    if(file.is_open()){
        file >> this->numObject;
        file >> this->numRobot;
        vector<int> head(numRobot+numObject+2,0);
        for(int i=1;i<=numObject;i++)
            head[i]=1;
        matrix.push_back(head);
        for(int i=0;i<numObject;i++){
            vector<int> temp(numObject+1,0);
            for(int j=0;j<numRobot;j++){
                file >> curr;
                temp.push_back(curr);
            }
            temp.push_back(0);
            matrix.push_back(temp);
        }
        for(int i=0;i<numRobot;i++){
            vector<int> temp(numObject+numRobot+1,0);
            file>>curr;
            temp.push_back(curr);
            matrix.push_back(temp);
        }
        vector<int> temp(numObject+numRobot+2,0);
        matrix.push_back(temp);
        file.close();
        for(int i =0;i<numRobot+numObject+2;i++)
            parent.push_back(0);
        for(int i =0;i<numObject;i++)
            result.push_back(-1);
    }
    resMatrix = matrix;
}

bool Graph::bfSearch(int src, int sink){
    bool flag[numObject+numRobot+2];
    for(int i = 0;i<numObject+numRobot+2;i++){
        flag[i] = false;
    }
    queue <int> Q;
    Q.push(src);
    flag[src] = true;
    parent[src] = -1;

    while (!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        for (int x=t+1; x<numRobot+numObject+2; x++)
        {
            if (flag[x]==false && resMatrix[t][x] > 0)
            {
                Q.push(x);
                parent[x] = t;
                flag[x] = true;
            }
        }
    }

    return (flag[sink] == true);
}

void Graph::calculate()
{
    int p, v,temp=0;
    while (this->bfSearch(0, numObject+numRobot+1))
    {
        int curr = INT_MAX;

        //find the lowest valued edges in the path
        for (v=numObject+numRobot+1; v!=0; v=parent[v])
        {
            p = parent[v];
            if(resMatrix[p][v] < curr) curr = resMatrix[p][v];
        }


        //decrease the values of selected edges by following parent variables
        for (v = numObject+numRobot+1; v != 0; v=parent[v])
        {
            p = parent[v];

            //this part marks object-robot allocation
            if(p>numObject && p<numObject+numRobot+1){
                temp = p;
            }
            else if(p>0 && p<numObject+1){
                result[p-1] = temp-numObject;
            }
            resMatrix[v][p] += curr;
            resMatrix[p][v] -= curr;
        }
        maxflow = maxflow + curr;
    }
}

void Graph::writeResults(){
    cout << "Given transportation problem is solved by using graph that shown as following adjacency matrix..." << endl << endl;
    for(int i = 0;i<numObject+numRobot+2;i++){
        cout << "   ";
        for(int j = 0;j<numObject+numRobot+2;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    ofstream f("output.txt");
    f << "The number of processed objects is " << maxflow << "." << endl;
    for(int i = 0;i<numObject;i++){
        if(result[i]!=-1){
            f << "Object " << i << " will be moved by Robot " << result[i] << "."<<endl;
        }
        else{
            f << "Object " << i << " will not be moved." << endl;
        }
    }
    f.close();
    cout << "The number of processed objects is " << maxflow << "." << endl;
    cout << "Carrier assignments are written to output.txt file." << endl << endl;
}

int main()
{
    Graph g = Graph();
    g.fillMatrix("input.txt");
    g.calculate();
    g.writeResults();
    return 0;
}
