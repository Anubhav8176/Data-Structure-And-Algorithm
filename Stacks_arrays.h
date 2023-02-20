#include <iostream>
using namespace std;

class Stack{
    public:
    int size;
    int Top;
    int *s;
    char *S;

    // All the operations are given below and performed by using Arrays.
    void push(Stack *st, int x);
    int pop(Stack *st);
    int peek(Stack st, int pos);
    int stackTop(Stack st);
    int isEmpty(Stack st);
    int isfull(Stack st);
    int isBalance(char *exp);
    void Display(Stack st);
};

// Fuction will be used for inserting the new element at the top of Stack.
void Stack :: push(Stack *st, int x){
    if(st->Top == st->size - 1)
        cout << "Stack Overflow" << endl;
    else{
        st->Top++;
        st->s[st->Top] = x;
    }
}

// Fuction will delete the top most element in the Stack.
int Stack :: pop(Stack *st){
    int x = -1;
    if(st->Top == -1)
        cout << "Stack Underflow" << endl;
    else{
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}

// Function will tell the element at any particlur position in the stack.
int Stack :: peek(Stack st, int pos){
    int x = -1;
    if((st.Top - pos + 1) < 0)
        cout << "Invalid Position" << endl;
    else
        x = st.s[st.Top];
    return x;
}

// Function will give the element over which top is pointing.
int Stack :: stackTop(Stack st){
    if(st.Top == -1)
        return -1;
    else
        return st.s[st.Top];
}

// Function will check wether the stack is full or not.
int Stack :: isfull(Stack st){
    if(st.Top == (st.size - 1))
        return 1;
    else
        return 0;
}

// Function will check wether the stack is empty or not.
int Stack :: isEmpty(Stack st){
    if(st.Top == -1)
        return 1;
    else
        return 0;
}


int main(){
    Stack stk; 
    cout << "Enter the size of Stack" << endl;
    cin >> stk.size;
    stk.s = new int[stk.size];
    stk.Top = -1;
    stk.push(&stk, 50);
    stk.push(&stk, 40);
    stk.push(&stk, 30);
    stk.push(&stk, 20);
    stk.push(&stk, 10);
    cout << stk.pop(&stk) << endl;
    cout << stk.pop(&stk) << endl;
    cout << stk.pop(&stk) << endl;
    cout << stk.pop(&stk) << endl;
    cout << stk.pop(&stk) << endl;
    cout << stk.size << endl;
    
    return 0;
}