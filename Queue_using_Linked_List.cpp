#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    void enqueue(int x);
    int dequeue();
    void Display();
    int isEmpty(Node queue);
}*front = NULL, *rear = NULL;

// Fuction will create the queue.
void Node ::enqueue(int x){
    Node *t = new Node;
    if(t == NULL)
        cout << "Queue is full" << endl;
    else{
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

// Function will delete the element from the queue.
int Node :: dequeue(){
    int x = -1;
    Node *t = new Node;
    if(front == NULL)
        cout << "Queue is empty" << endl;
    else{
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

// Function will print all the element in the Queue.
void Node :: Display(){
    Node *p = front;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int main(){
    Node queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.Display();
    cout << queue.dequeue();

    return 0;
}