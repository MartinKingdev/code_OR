#include<iostream>
#include "grapheOriente.hpp"
#include "list.hpp"

using namespace std;


int main(){
    grapheOriente g1(2);
    g1.addVertices();
    g1.addEgde(1,2);
    g1.addEgde(2,1);
    //g1.addEgde(1,3);
    //g1.addEgde(3,4);
    //g1.addEgde(3,1);
    g1.displayVertices();
    g1.displayEdges();
    //g1.addEgde(3,3);
    g1.displayEdges();
    g1.updateSuccessors();
    g1.updatePredecessors();
    /*for (int i = 1; i <=3; i++)
    {
        //g1.updatePredecessor(i);
        cout << i << endl;
        g1.updateSuccessors(i);
        cout << i << endl;
    }*/
    //g1.displayVertices();
    g1.displayVertices();
    //cout << g1.vertexDegreExt(1) << endl;
    //cout << g1.vertexDegreInt(1) << endl;
    //cout << g1.existPath(1,2) << endl;
    //cout << g1.existPath(3,4) << endl;
    //cout << g1.existPath(3,2) << endl;
    //cout << g1.existPath(3,4) << endl;
    //cout << g1.existPath(1,4) << endl;
    //cout << " Coucou !" << endl;
    g1.ifConnex();
    return 0;
}
