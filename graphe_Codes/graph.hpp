#ifndef Graph_HPP
#define Graph_HPP

#include <iostream>
#include <list>
#include <vector>
#include<map>

using namespace std;

struct adjacent
{
    list<int> successors;
    list<int> predeccessors;
};


class Graph
{
private:
    // nous permet de definir un Graphe oriente
    int _Oriented; 
    // nous permet de representer notre Graphe a partir de : numero_du_Sommet, list_Successeurs, vector_Predecessors
    map<int, adjacent> _graph; 
    map<pair<int,int>,double> edges;
    int _Order; 
public:
    Graph(int _is_Oriented = 0, int _number = 0);
    Graph(Graph & _gr);
    ~Graph();
    void addEgde(int,int);
    void addEgdeweight(int,int,double);
    void displaysuccessor(int);
    void displayVertices();
    list<int> getSuccessor(int);
    double getEdgesWeight(int,int);
    // void displayVertices();
    void displayEdges();
    int vertexDegre(int);
    int vertexDegreExt(int);
    int vertexDegreInt(int);
    int getOrder();
    bool existPath(int,int);
    bool ifConnex();
    int nombreChromatique();
};


#endif
