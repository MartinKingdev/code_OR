#include<iostream>
#include "graph.hpp"
#include<vector>
#include<stack>
#include<queue>


Graph::Graph(int _is_Oriented , int _number){
    _Oriented = _is_Oriented;
    _Order = _number;
    for (int i = 0; i < _number; i++)
    {
        _graph[i+1].successors.resize(0);
        _graph[i+1].predeccessors.resize(0);
    }
}

Graph::Graph(Graph& _gr): _Oriented(_gr._Oriented), _Order(_gr._Order) {
    _graph = _gr._graph;
}

Graph::~Graph(){}
// pour controler le fait que le Graphe est simple et que les arcs ou arr_graphs ajouter ont des sommets valides
void Graph::addEgde(int _a, int _b){
    if (_a <=0 || _a > _Order || _b <=0 || _b > _Order || _a==_b)
    {
        cout << "Impossible d'ajouter de une telle arr_graph" << endl;
    }
    else
    {
        edges[make_pair(_a,_b)] = 1;
        if (_Oriented == 1)
        {
            _graph[_a].successors.push_back(_b);
            _graph[_b].predeccessors.push_back(_a);
        }
        else
        {
            _graph[_a].successors.push_back(_b);
            _graph[_b].successors.push_back(_a);
        }   
    }
}
void Graph::addEgdeweight(int _a,int _b, double weight = 1){
    if (_a <=0 || _a > _Order || _b <=0 || _b > _Order || _a==_b)
    {
        cout << "Impossible d'ajouter de une telle arr_graph" << endl;
    }
    else
    {
        addEgde(_a,_b);
        edges[make_pair(_a,_b)] = weight;
    }
    
}

void Graph::displayVertices(){
    for (int i = 0; i < _Order; i++)
    {
        displaysuccessor(i+1);
    }
}

int Graph::vertexDegreExt(int _a){
    int degreExt = 0;
    if (_graph.find(_a) != _graph.end())
    {
        degreExt = _graph[_a].successors.size();
    }
    return degreExt;
}

int Graph::vertexDegreInt(int _a){
    int degreInt = 0;
    if (_Oriented == 1)
    {
        if (_graph.find(_a) != _graph.end())
        {
            degreInt = _graph[_a].predeccessors.size();
        }
    }
    return degreInt;
}
int Graph::vertexDegre(int _a){
    return vertexDegreExt(_a)+vertexDegreInt(_a); 
}

bool Graph::existPath(int _a,int _b){
    bool _trouve = false;
    stack<int , vector<int>> _pile;
    vector<bool> _marque;
    _marque.assign(_Order,false);
    _pile.push(_a);
    while (_pile.empty()==false)
    {
        int _el = _pile.top();
        if (_marque[_el-1] == false)
        {
            _marque[_el-1] = true;
        }
        _pile.pop();
        for (auto  _i = _graph[_el].successors.begin(); _i!=_graph.find(_el)->second.successors.end(); _i++)
        {
            if (*_i == _b)
            {
                _trouve = true;
                break;
            }
            else
            {
                if (_marque[*_i-1] == false)
                {
                    _pile.push(*_i);
                }
            }
        }
    }
    return _trouve;
}

bool Graph::ifConnex(){
    bool _is_Connex = true;
    for (int i=0; i<_graph.size(); i++)
    {
        for (int j = 0; j<_graph.size() && i!=j; j++)
        {
            if (existPath(i+1,j+1) == false)
            {
                _is_Connex = false;
                break;
            }
        }
    }
    return _is_Connex;
}

int Graph::nombreChromatique(){
    int _nombre_Chromatique = 1;
    if (_Oriented == 0)
    {
        vector <int> _couleur;
        _couleur.assign(_Order,0);
       for (int i = 0; i < _Order; i++)
       {
            int _couleur_Recente = 1;   
        //cout << "Entrez dans le for " << endl;
            //int _indice =0;
            queue<int, list<int>> _couleurSuccessor;
            //cout << "Entrez dans le for "  << endl;
            for (auto _succ : _graph[i+1].successors)
            {
                //cout << "Entrez dans le for " << _succ-1 << endl;
                _couleurSuccessor.push(_couleur[_succ-1]);
            }

            
            while(_couleurSuccessor.empty()==false)
            {
                if (_couleur_Recente == _couleurSuccessor.front())
                {
                    _couleur_Recente++;
                }
                _couleurSuccessor.pop();
            }
            _couleur[i] = _couleur_Recente;
            if (_couleur_Recente>_nombre_Chromatique)
            {
                _nombre_Chromatique++;
            }
            cout << i+1 << " : "  << _couleur[i] << endl;
       }
    }
    return _nombre_Chromatique;
}
int Graph::getOrder(){
    return _Order;
}

void Graph::displaysuccessor(int _a){
    if (_a > _Order || _a<=0)
    {
        cout << "Le sommet n'existe pas !" << endl;
    }
    else
    {
        cout << _a << " : ";
        for (auto i:_graph[_a].successors)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void Graph::displayEdges(){
    for (auto i : edges)
    {
        cout << "<< " << i.first.first << " : " << i.first.second << " >> " << i.second << endl;
    }
}

list<int> Graph::getSuccessor(int i){
    return _graph[i].successors;
}

double Graph::getEdgesWeight(int u,int v){
    return edges[make_pair(u,v)];
}
