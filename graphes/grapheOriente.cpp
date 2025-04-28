#include<iostream>
#include<math.h>
//#include"list.hpp"
#include"grapheOriente.hpp"
using namespace std;


void grapheOriente::addVertices(){
    for (int i = 1; i <= order; i++)
    {
        vertex* el = new vertex;
        el->data = i;
        el->next = NULL;
        if (vertices == NULL)
        {
            el->next = NULL;
            vertices = el;
        }
        else
        {
            vertex* temp = vertices;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = el;
        }
    }
}
void grapheOriente::addEgde(int a, int b){
    if (a>order || b> order || b==a)
    {
        cout << "Impossible d'ajouter un tel arc ! " << endl;
    }
    else
    {
        edge* el = new edge;
        el->initData = a;
        el->lastData = b;
        el->next = edges;
        edges = el;
    }
    
}
void grapheOriente::displayEdges(){
    edge* el = edges;
    cout << "[ ";
    while (el!=NULL)
    {
        cout << "{" << el->initData << ";" << el->lastData << "} ";
        el = el->next;    
    }
    cout << "]" << endl;
}
void grapheOriente::displayVertices(){
    cout << " Vertices :\n";
    vertex* el = vertices;
    while (el!=NULL)
    {
        cout << el->data << " - ";
        /*
        el->successor.displaylist();
        el->predecessor.displaylist();
        */
        el = el->next;
    }
    //cout << "++++++++++++++++\n";
}
void grapheOriente::updateSuccessors(){
    vertex* elt = vertices;
    while (elt!=NULL)
    {
        edge* e = edges;
            while (e!=NULL)
            {
                if (e->initData == elt->data)
                {
                    if (!elt->successor.ifInlist(e->lastData))
                    {
                        elt->successor.addTohead(e->lastData);
                    }
                }
                e = e->next;        
            }
        elt = elt->next;
    }
}



void grapheOriente::updatePredecessors(){
    vertex* elt = vertices;
    while (elt!=NULL)
    {
        edge* e = edges;
            while (e!=NULL)
            {
                if (e->lastData == elt->data)
                {
                    if (!elt->predecessor.ifInlist(e->initData))
                    {
                        elt->predecessor.addTohead(e->initData);
                    }
                }
                e = e->next;        
            }
        elt = elt->next;
    }
}

int grapheOriente::vertexDegre(int a){
    vertex* elt = vertices;
    if (elt == NULL)
    {
        return 0;
    }
    
    while (elt->data!=a)
    {
        elt = elt->next;
    }
    return elt->successor.getlenght();
    
}
int grapheOriente::vertexDegreInt(int a){
    vertex* elt = vertices;
    int n = 0;
    if (elt != NULL)
    {
        while (elt->data!=a)
        {
            elt = elt->next;
        }
        n = elt->predecessor.getlenght();
    }
    return n;
}
int grapheOriente::vertexDegreExt(int a){
    vertex* elt = vertices;
    int n = 0;
    if (elt != NULL)
    {
        while (elt->data!=a)
        {
            elt = elt->next;
        }
        n = elt->successor.getlenght();
    }
    return n;
}
bool grapheOriente::existPath(int a,int b){
    //bool val = false;
    vertex* elt = vertices;
    while (elt->data != a)
    {
        elt = elt->next;
    }
    if (elt->successor.getHead()!= NULL)
    {
        if (elt->successor.ifInlist(b))
        {
            return true; 
        }
        else
        {
            existPath(elt->successor.getHead()->data,b);
        }
    }
    else
    {
        return false;
    }
    
    
    /*
        node<int>* el = elt->successor.getHead();
        while (el!= NULL)
        {   
            val = existPath(el->data,b);
            el = el->next;
        }
        */        //cout << " Val vaut : " << val << endl;
    /*
    if (val)
    {
        return true;
    }
    else{
        return false;
    }
    */
}

bool grapheOriente::ifConnex(){
    vertex* elt = vertices;
    while (elt!=NULL)
    {
        vertex* eltnext = vertices;
        while (eltnext != elt && eltnext != NULL)
        {
            if (existPath(elt->data,eltnext->data) == false)
            {
                cout << " Le grapheOriente n'est pas connexe !" << endl;
                return false;
            }
            eltnext = eltnext->next;
        }
        elt = elt->next;
    }
    cout << " Le grapheOriente est bien connexe !" << endl;
    return false;
}


