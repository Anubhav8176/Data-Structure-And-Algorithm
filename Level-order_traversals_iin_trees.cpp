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

void Tree :: Levelorder(Node* root){
    Queue q(100);
    cout << root->data << " ";
    q.enqueue(root);
    while(! q.isEmpty()){
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

int main(){
    Tree t;
    t.createTree();
    cout << "Levelorder is " << endl;
    t.Levelorder(t.root);
    cout << endl;

    return 0;
}