#include <iostream>
#include "Queue_LL.h"

using namespace std;

class Tree{
public:
    Node* root;
    Tree(){
        root = NULL;
    }
        void createTree();
        int Height(Node *root);
        int count(Node* root);
};

// Function will create the tree.
void Tree :: createTree(){
    Node *p, *t;
    int x;
    Queue q(100);
    cout << "Enter root value " << flush;
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(q.isEmpty() != true){
        p = q.dequeue();

        // For left child.
        cout << "Enter Left child of " << p->data << " " << flush;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        // For right child.
        cout << "Enter right child of " << p->data << " " << flush;
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

int Tree :: count(Node* p){
    int x, y;
    if(p!= NULL){
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int Tree :: Height(Node* p){
    int x = 0, y = 0;
    if(p != NULL){
        x = Height(p->lchild);
        y = Height(p->rchild);
        if(x > y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int main(){
    Tree t;
    t.createTree();
    cout << "Number of nodes are " << t.count(t.root) << endl;
    cout << "Height of the tree is " << t.Height(t.root) << endl;        

    return 0;
}