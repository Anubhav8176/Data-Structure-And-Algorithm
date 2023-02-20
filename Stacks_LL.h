#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Stack{
    private:
    Node *Top;
    public:
    Stack(){
        Top = NULL;
    }

    // Following are the operations on stack using Linked List.
    void push(int x);
    int pop();
    int peek(int pos);
    int stackTop();
    int isEmpty();
    int isFull();
    void Display();
};

// Function will help to add a new element at the top of Stack.
void Stack :: push(int x){
    Node *t = new Node;
    if(t == NULL)
        cout << "Stack Overflow" << endl;
    else{
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

// Function will help to delete an element at the top of Stack.
int Stack :: pop(){
    Node *p;
    int x = -1;
    if(Top == NULL)
        cout << "Stack is empty" << endl;
    else{
        p = Top;
        Top = Top->next;
        x = p->data;
        delete p;
    }
    return x;
}

// Function will help to know the element at particular position.
int Stack :: peek(int pos){
    int x = -1;
    Node *p = Top;
    for(int i = 0; (p != NULL) && i < (pos - 1); i++)
        p = p->next;
    if(p != NULL)
        return p->data;
    else
        return -1;
}

// Function will help to check the element at the Top.
int Stack :: stackTop(){
    if(Top != NULL)
        return Top->data;
    else
        return -1;
}

// Function will check wether the Stack is empty or not.
int Stack :: isEmpty(){
    if(Top == NULL)
        return 1;
    else
        return 0;
}

// Function will check wether the Stack is full or not.
int Stack :: isFull(){
    Node *t = new Node;
    if(t != NULL)
        return 1;
    else
        return 0;
}

// Function will display the elements of the stack.
void Stack :: Display(){
    Node *p = Top;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int main(){
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.Display();

    cout << stk.pop() << endl;
    
    stk.Display();

    return 0;
}