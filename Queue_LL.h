#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(){
        front = -1;
        rear = -1;
        size = 10;
        Q = new Node*[size];
    }
    Queue(int size){
        front = -1;
        rear = -1;
        this->size = size;
        Q = new Node*[this->size];
    }
    // Operation on the Queues are below.
    void enqueue(Node *x);
    Node* dequeue();
    void Display();
    bool isEmpty();
    void isFull();
};

// Function will isert the element in the Queue.
void Queue :: enqueue(Node *x){
    if(rear == size - 1)
        cout << "Queue is full" << endl;
    else{
        rear++;
        Q[rear] = x;
    }
}

// Function will delete the element from Queue.
Node* Queue ::dequeue(){
    Node* x = NULL;
    if(front == rear)
        cout << "Queue is empty" << endl;
    else{
        front++;
        x = Q[front];
    }
    return x;
}

// Function will Display the whole Queue.
void Queue :: Display(){
    for(int i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << endl;
}

// Function will check wether Queue is empty or not.
bool Queue :: isEmpty(){
    if(front == rear)
        return true;
    else
        return false;
}

// Function will check wether Queue is full or not.
void Queue :: isFull(){
    if(rear == (size - 1))
        cout << "Queue is full." << endl;
    else
        cout << "Queue is not full." << endl;
}