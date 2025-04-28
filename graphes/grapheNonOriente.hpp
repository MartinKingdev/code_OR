#include<iostream>
#include<math.h>
#include"list.hpp"
#include"grapheOriente.hpp"
using namespace std;

class grapheNonOriente: public grapheOriente
{
public:
    grapheNonOriente(int n):grapheOriente(n){}
    ~grapheNonOriente(){}
    void updateSuccessors();
};

void grapheNonOriente::updateSuccessors(){
    vertex* elt = vertices;
    while (elt!=NULL)
    {
        edge* e = edges;
            while (e!=NULL)
            {
                if (e->initData == elt->data)
                {
                    elt->successor.addTohead(e->lastData);
                    e = e->next;
                }
                else if(e->lastData == elt->data)
                {
                    elt->successor.addTohead(e->initData);
                    e = e->next;
                }
                else
                {
                    e = e->next;
                }    
            }
        elt = elt->next;
    }
}
