// Insertion will be done from rear and deletion will be from front.
#include <bits/stdc++.h>
using namespace std;

class Queue{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(){
        front = -1;
        rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size){
        front = -1;
        rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    // Operation on the Queues are below.
    void enqueue(int x);
    int dequeue();
    void Display();
    void isEmpty();
    void isFull();
};

// Function will isert the element in the Queue.
void Queue :: enqueue(int x){
    if(rear == size - 1)
        cout << "Queue is full" << endl;
    else{
        rear++;
        Q[rear] = x;
    }
}

// Function will delete the element from Queue.
int Queue ::dequeue(){
    int x = -1;
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
void Queue :: isEmpty(){
    if(front == rear)
        cout << "Queue is Empty." << endl;
    else 
        cout << "Queue is not Empty." << endl;
}

// Function will check wether Queue is full or not.
void Queue :: isFull(){
    if(rear == (size - 1))
        cout << "Queue is full." << endl;
    else
        cout << "Queue is not full." << endl;
}


int main()
{
    int a;
    Queue q;
    for(int i = 0; i < 10; i++){
        cin >> a;
        q.enqueue(a);
    }
    q.Display();
    q.isFull();

    return 0;
}