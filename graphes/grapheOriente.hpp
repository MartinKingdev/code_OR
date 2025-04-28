#include<iostream>
#include<math.h>
#include"list.hpp"
using namespace std;
struct edge
{
    int initData, lastData;
    edge* next;
    void affiche(){
        cout << "{" << initData << ";" << lastData << "}," ;
    }
};
struct vertex{
    int data;
    list<int> successor;
    list<int> predecessor;
    vertex* next;
};


class grapheOriente
{
protected:
    int order;
    vertex* vertices;
    edge* edges;
public:
    grapheOriente(int n){
        order = n;
        vertices = NULL;
        edges = NULL;
    }
    ~grapheOriente(){        
        //delete[] vertices;
    }
    void addEgde(int a, int b);
    void addVertices();
    void displayVertices();
    void displayEdges();
    void updateSuccessors();//int a
    void updatePredecessors();
    int vertexDegre(int);
    int vertexDegreExt(int);
    int vertexDegreInt(int);
    bool existPath(int,int);
    bool ifConnex();
    
};