#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    // All the operations are performed by following functions.
    void create(int A[], int n);
    void Display(Node *h);
    void Insert(Node *p, int index, int x);
    int Counting(Node *p);
    int Delete(Node *p,int index);
} * Head;

// This function will create a Circular Linked List.
void Node ::create(int A[], int n){
    Node *last, *t;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// This fuction will Display the circular Linked List.
void Node ::Display(Node *h){
    // This will Display the elements by using Iteration.
    do{
        cout << h->data << " ";
        h = h->next;
    } while (h != Head);

    // This will Display the elements by using Recurssion.
    // static int flag = 0;
    // if(h != Head || flag == 0){
    //     flag = 1;
    //     cout << h->data << " ";
    //     Display(h->next);
    // }
    // flag = 0;
}

// This function will count the length of Circular Linked List.

int Node ::Counting(Node *p){
    int count = 0;
    do{
        count++;
        p = p->next;
    } while (p != Head);
    return count;
}

// This function will insert a new node in a circular Linked List.

void Node ::Insert(Node *p, int index, int x){
    Node *t;
    if ((index < 0) || (index > Counting(p)))
        return;
    else{
        if (index == 0){
            t = new Node;
            t->data = x;
            if (Head == NULL)
            {
                Head = t;
                Head->next = Head;
            }
            else{
                while (p->next != Head)
                    p = p->next;
                p->next = t;
                t->next = Head;
                Head = t;
            }
        }
        else{
            for (int i = 0; i < (index - 1); i++)
                p = p->next;
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

// This fuction will delete the elemens from a circular Linked List.

int Node :: Delete(Node *p,int index){
    Node *q;
    int x;
    if((index < 0) || (index > Counting(Head)))
        return -1;
    if(index == 1){
        while(p->next != Head)
            p = p->next;
        x = Head->data;
        if(Head == p){
            delete Head;
            Head = NULL;
        }
        else{
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else{
        for(int i = 0; i < (index - 2); i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}


int main()
{
    int A[] = {2, 3, 4, 5, 6};
    Node Circular;
    Circular.create(A, 5);
    Circular.Display(Head);
    cout << endl;
    // Circular.Insert(Head, 5, 10);
    cout << Circular.Delete(Head, 1) << endl;
    Circular.Display(Head);

    return 0;
}
