#include <bits/stdc++.h>
using namespace std;

class Queue{
public:
    int size;
    int front;
    int rear;
    int *Q;

    // All the operations are given below.
    void Create(Queue *q, int s);
    void enqueue(Queue *q, int x);
    int dequeue(Queue *q);
    void Display(Queue q);
};

// Function will create the Circular queue.
void Queue :: Create(Queue *q, int s){
    q->size = s;
    q->front = q->rear = 0;
    q->Q = new int[q->size];
}

// Function will enqueue the elements.
void Queue :: enqueue(Queue *q, int x){
    if((q->rear + 1)%q->size == q->front)
        cout << "Queue is full." << endl;
    else{
        q->rear = (q->rear + 1) % q->size;
        Q[q->rear] = x;
    }
}

// Function will delete the element from Queue.
int Queue ::dequeue(Queue *q){
    int x = -1;
    if(q->front == q->rear)
        cout << "Queue is empty" << endl;
    else{
        q->front = (q->front + 1)%q->size;
        x = Q[q->front];
    }
    return x;
}

// Function will Display the whole Queue.
void Queue :: Display(Queue q){
    int i = q.front + 1;
    do{
        cout << q.Q[i] << " ";
        i = (i + 1)%q.size;
    }while(i != (q.rear + 1)%q.size);
    cout << endl;
}


int main(){
    Queue q;
    q.Create(&q, 5);

    q.enqueue(&q, 10);
    q.enqueue(&q, 20);
    q.enqueue(&q, 30);
    q.enqueue(&q, 40);
    
    q.Display(q);

    return 0;
}