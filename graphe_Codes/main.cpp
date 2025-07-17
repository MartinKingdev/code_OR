#include<iostream>
#include "graph.hpp"
#include "graphAlgorithms.cpp"
#include<fstream>

using namespace std;

int main(){
    Graph g1(0,6);
    //Graph g1(1,6);
    ifstream _graphe("graphe.txt");

    int source, destination;
    while (_graphe >> source >> destination)
    {
        g1.addEgdeweight(source, destination,1);
        //g1.addEgde(source, destination);
    }

    cout << "****** Affichage des sommmets avec leur successeurs ********"<< endl;
    g1.displayVertices();
    cout << "************************************************************"<< endl;
    cout << "Ordre du graphe : " << g1.getOrder() << endl;
    cout << "Le degre du sommet 4 : " << g1.vertexDegre(4) << endl;
    cout << "Le degre du sommet 1 : " << g1.vertexDegre(1) << endl;
    cout << "Le degre du sommet 2 : " << g1.vertexDegre(2) << endl;
    

    if (g1.existPath(1,6))
    {
        cout << "Il existe un chemin entre les sommets " << 1 << " et " << 6 << endl;
    }
    else
    {
        cout << "Pas de chemin existant " << endl;
    }

    if (g1.ifConnex())
    {
        cout << "Le graphe est connexe"  << endl;

    }
    else
    {
        cout << "Le graphe n'est pas connexe" << endl;
    }

    cout << "Nombre chromatique de mon graphe : " << g1.nombreChromatique() << endl;

    g1.addEgdeweight(2,5,1);
    cout << "Apres l'ajout de l'arret 2--5" << endl;
    if (g1.ifConnex())
    {
        cout << "Le graphe est connexe"  << endl;
    }
    else
    {
        cout << "Le graphe n'est pas connexe" << endl;
    }
    
    cout << "Nombre chromatique de mon graphe : " << g1.nombreChromatique() << endl;
    
    g1.displayEdges();
    DjikstraAlgorithm(1,g1);
    return 0;
}