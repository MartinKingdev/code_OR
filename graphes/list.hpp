#include<iostream>

using namespace std;

template <typename T> struct node{
    T data;
    node* next;
};

template <typename T> class list
{
private:
    node<T>* head;
    int length;
public:
    list(){
        head = NULL;
        length = 0;
    }
    ~list(){
        while (head!=NULL)
        {
            deleteAthead();
        }
        //cout << "destruction complete faite !" << endl;
    }
    void addTohead(T);
    void deleteAthead();
    bool ifInlist(T);
    /*
    
    */
    void deleteAnyNode(T);
   
    void displaylist();
    
    node<T>* getHead(){
        return head;
    }
    void setHead(node<T>* h){
        head = h;
    }
    void listLength(){
        cout << "The list have " << length << " elements ! " << endl;
    }
    int getlenght(){
        return length;
    }
};
template <typename T> void list<T>::addTohead(T val){
    node<T>* elt = new node<T>;
    elt->next = head;
    elt->data = val;
    head = elt;
    length++;        
}
template <typename T> void list<T>::deleteAthead(){
    node<T>* temp = head;
    if (temp == NULL)
    {
        return ;
    }
    head = temp->next;
    delete temp;
    length--;
}
template <typename T> void list<T>::displaylist(){
        node<T>* temp = head;
        if (temp == NULL)
        {
            cout << "\nListe vide! \n" ;
            return ;
        }
        cout << endl;
        while (temp != NULL)
        {
            cout << temp->data << " =>> ";
            temp = temp->next;
        }
        cout << endl;
    }

template <typename T> void list<T>::deleteAnyNode(T val){
    node<T>* temp = head;
    if (temp == NULL)
    {
        return ;
    }
    if (temp->data == val)
    {
        deleteAthead();
    }
    else
    {
        while (temp->next!= NULL)
        {
            if (temp->next->data == val)
            {
                cout << "supression" << endl;
                node<T>* del = temp->next;
                temp->next = del->next;
                delete del;
                length--;
                return ;
            }
            temp = temp->next;
        }
    }
    if (temp->next==NULL)
    {
        cout << "L'element n'est pas dans la liste !" << endl;
        return ;
    }    
}

template <typename T> bool list<T>::ifInlist(T a){
    node<T>* temp = head;
    while (temp != NULL)
    {
        if (temp->data == a)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}