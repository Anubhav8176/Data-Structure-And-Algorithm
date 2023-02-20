#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;

    // All the operations are performed by following functions.
    void Create(int A[], int n);
    void Display(Node *p);
    int Length(Node *p);
    void Insert(Node *p, int index, int x);
    int Delete(Node *p, int index);
    void Reverse(Node *p);
}*first;

// The function will create the new Doubly Linked List.

void Node :: Create(int A[],int n){
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;
    for(int i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// This function will used to count the length of the Doubly Linked LIst.

int Node :: Length(Node *p){
    int length = 0;
    while(p != NULL){
        length++;
        p = p->next;
    }
    return length;
}

// This function will used to display all the elements of Doubly Linked List.

void Node :: Display(Node *p){
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

// This function will help to insert in an element in a Doubly liked list.

void Node :: Insert(Node *p, int index, int x){
    Node *t, *q;
    if((index < 0) || (index > Length(p)))
        return;
    else{
        if(index == 1){
            t = new Node;
            t->data = x;
            first->prev = t;
            t->next = first;
            t->prev = NULL;
            first = t;
        }
        else{
            for(int i = 0; i < (index - 1); i++)
                p = p->next;
            q = p->next;
            t = new Node;
            t->data = x;
            t->prev = p;
            t->next = q;
            p->next = t;
            q->prev = t;
        }
    }
}

// This function will help to delete the element from Doubly Linked Lists.

int Node :: Delete(Node *p, int index){
    Node *last, *q;
    int x;
    if((index < 0) || (index > Length(p)))
        return -1;
    else{
        if(index == 1){
            p = first;
            first = first->next;
            x = p->data;
            delete p;
            if(first != NULL)
                first->prev = NULL;
        }
        else{
            for(int i = 0; i < (index - 2); i++)
                p = p->next;
            q = p->next;
            last = q->next;
            p->next = q->next;
            last->prev = q->prev;
            x = q->data;
            delete q;
        }
    }
    return x;
}

// This Fuction will help to reverse the whole linked lists.
void Node :: Reverse(Node *p){
    Node *temp;
    p = first;
    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if((p != NULL) && (p->next == NULL))
            first = p;
    }
}


int main(){
    Node Doubly;
    int A[] = {6, 9, 3, 7, 2};
    Doubly.Create(A, 5);
    Doubly.Display(first);
    cout << endl;
    // cout << Doubly.Length(first) << endl;
    // Doubly.Insert(first, 3, 5);
    // Doubly.Delete(first, 1);
    Doubly.Reverse(first);
    Doubly.Display(first);

    return 0;
}