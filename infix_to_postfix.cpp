#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Stack{
    public:
    int size;
    int Top;
    char *s;

    void push(Stack *st, char x);
    char pop(Stack *st);
    int stackTop(Stack st);
    char* Convert(char *infix);
    int isEmpty(Stack st);
    int Evaluate(char *postfix);
};

// Fuction will be used for inserting the new element at the top of Stack.
void Stack :: push(Stack *st, char x){
    if(st->Top == st->size - 1)
        cout << "Stack Overflow" << endl;
    else{
        st->Top++;
        st->s[st->Top] = x;
    }
}

// Fuction will delete the top most element in the Stack.
char Stack :: pop(Stack *st){
    char x = -1;
    if(st->Top == -1)
        cout << "Stack Underflow" << endl;
    else{
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}

// Function will give the element over which top is pointing.
int Stack :: stackTop(Stack st){
    if(st.Top == -1)
        return -1;
    else
        return st.s[st.Top];
}

// Function will check wether the stack is empty or not.
int Stack :: isEmpty(Stack st){
    if(st.Top == -1)
        return 1;
    else
        return 0;
}

// Check wether the character is operand or not.
int isOperand(char x){
    if((x == '+') || (x == '-') || (x == '*') || (x == '/'))
        return 0;
    else
        return 1;
}

// Checking the precedence.
int precedence(char x){
    if((x == '+') || (x == '-'))
        return 1;
    else if((x == '+') || (x == '-'))
        return 2;
    else
        return 0;
}

// For conversion of infix to postfix.
char* Stack :: Convert(char *infix){
    Stack st;
    st.Top = -1;
    st.size = strlen(infix);
    char *postfix = new char[st.size + 1];
    int i = 0, j = 0;
    
    // Traversing through the infix char.
    while(infix[i] != '\0'){
        // Checking that element is operand or not i.e varaible or not.
        if(isOperand(infix[i]) == 1){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        // If not operand then it must be operator so we check the precedence
        else{
            // Checking the precedence of the operator.
            if(precedence(infix[i]) > precedence(stackTop(st))){
                push(&st, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(&st);
                j++;
            }
        }
    }
    // Copying the remaining element in st to the postfix.
    while( !isEmpty(st))
        postfix[j++] = pop(&st);
    postfix[j] = '\0';
    return postfix;
}

// Function will be used to evaluate any postfix expression.
int Stack :: Evaluate(char *postfix){
    Stack st;
    int i, x1, x2, r;
    for(i = 0; postfix[i] != '\0'; i++){
        if(isOperand(postfix[i]))
            push(&st, (postfix[i] - '0'));
        else{
            x2 = pop(&st);
            x1 = pop(&st);
            switch(postfix[i]){
                case '+': r = x1 + x2;
                    push(&st, r);
                    break;
                case '-': r = x1 - x2;
                    push(&st, r);
                    break;
                case '*': r = x1 * x2;
                    push(&st, r);
                    break;
                case '/': r = x1 / x2;
                    push(&st, r);
                    break;  
            }
        }
    }
    return pop(&st);
}


int main(){

    Stack Pstfix;
    char *postfix = "234*+82/-";
    cout << Pstfix.Evaluate(postfix) << endl;

    return 0;
}