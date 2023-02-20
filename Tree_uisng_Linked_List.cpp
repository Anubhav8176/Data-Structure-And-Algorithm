#include <bits/stdc++.h>
// We have includednthe whole Queue in our program by this header file.
#include "Queue_LL.h"
using namespace std;

class Tree{
public:
    Node* root;
    Tree(){
        root = NULL;
    }
        void createTree();
        void Preorder(){Preorder(root);}
        void Preorder(Node *p);
        void Postorder(Node *p);
        void Inorder(Node *p);
        void Levelorder(Node *root);
        int Height(Node *root);
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

// The function will help to display the Tree in Preorder recurrsively.
void Tree :: Preorder(Node *p){
    if(p != NULL){
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// The function will help to display the Tree in Inorder recurrsively.
void Tree :: Inorder(Node *p){
    if(p != NULL){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

// The function will display the Tree in Postorder recurrsively.
void Tree ::Postorder(Node *p){
    if(p != NULL){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

// This function will help to display the Tree in Levelorder recurrsively.
void Tree :: Levelorder(Node *root){
    Queue q(100);
    cout << root->data << " ";
    q.enqueue(root);

    while(!q.isEmpty()){ 
        root = q.dequeue();
        if(root->lchild){
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if(root->rchild){
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
}

// This function will display the Height of the tree.
int Tree :: Height(Node *root){
    int x = 0, y = 0;
    if(root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x > y)
        return x + 1;
    else
        return y + 1;
}

int main(){
    Tree t;
    t.createTree();
    cout << "Preorder is " << endl;
    t.Preorder(t.root);
    cout << endl;
    cout << "Inorder is " << endl;
    t.Inorder(t.root);
    cout << endl;
    cout << "Postorder is " << endl;
    t.Postorder(t.root);
    cout << endl;
    cout << "Level Order is " << endl;
    t.Levelorder(t.root);

    return 0;
}
