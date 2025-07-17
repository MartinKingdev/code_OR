#include"graph.hpp"
#include<bits/stdc++.h>

using namespace std;

bool isIn(vector<int>& E, int A){
    bool In =  false;
    for (auto i:E)
    {
        if (i==A)
        {
            In = true;
        }
    }
    return In;
    
}

bool operator<(pair<int,double> a, pair<int,double> b){
    return (a.second < b.second);
}
void DjikstraAlgorithm(int initNode, Graph &g1){
    vector<double> distance(g1.getOrder());
    vector<int> father(g1.getOrder());
    priority_queue <pair<int,double>, deque<pair<int,double>>, greater<pair<int,double>>> F;
    vector<int> E;
    // vector<vector<int>> Cout(g1.getOrder(),vector<int>(g1.getOrder()));
    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }
    
    for (size_t i = 0; i < g1.getOrder(); i++)
    {
        if (i == initNode-1)
        {
            distance[i] = 0;
        }
        else
        {
            distance[i] = LLONG_MAX;
        }
        father[i] = 0;
        F.push(make_pair(i+1,distance[i]));
    }
    
    while (!(F.empty()))
    {
        pair<int,double> U = F.top();
        int u = U.first;
        for (auto v : g1.getSuccessor(u))
        {
            if (isIn(E,v))
            {
                continue;
            }
            else
            {
                father[v-1] = u;
                distance[v-1] = min(distance[v-1],distance[u-1] + g1.getEdgesWeight(u,v));
                //cout << v << " " << distance[v-1] << ", ";
            }
        }
        //cout << endl;
        E.push_back(U.first);
        F.pop();
        //cout << U.first << " : " << U.second << endl;
        
    } 
    for (size_t i = 0; i < g1.getOrder(); i++){
        cout << i+1 << " :: ";
        cout << distance[i] << " : ";
        cout << father[i] << " " << endl;
    }
    cout << endl;
}