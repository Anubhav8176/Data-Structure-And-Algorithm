#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *rchild;
    Node *lchild;
}*root = NULL;

class BST
{
public:
    void Insert(int key);
    Node *RInsert(Node* P, int key);
    void Inorder(Node *p);
    Node *Search(int key);
    Node *Delete(Node * p, int key);
    int Height(Node *root);
    Node* Inpre(Node *p);
    Node* Insucc(Node *p);
};


// An iterative function for inserting elements on a BST.
void BST ::Insert(int key)
{
    Node* t = root;
    Node* p;
    Node* r;
    if(root == NULL){
        p = new Node;
        p->lchild = p->rchild =  NULL;
        p->data = key;
        root = p;
        return;
    }
    while(t != NULL){
        r = t;
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else
            return;
    }

    // Now t will point at NULL and r will be the tailing pointer that points
    // at the inserting position.
    p = new Node;
    p->lchild = p->rchild = NULL;
    p->data = key;

    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
    
}

// A recursive function to insert in the BST.
Node* BST ::RInsert(Node* p, int key){
    Node* t = NULL;
    if(p == NULL){
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    
    return p;

}

Node* BST ::Inpre(Node *p){
    while(p && p->rchild != NULL)
        p = p->rchild;
    
    return p;
}


// this function will give the succesor of current node.
Node* BST ::Insucc(Node *p){
    while(p && p->lchild != NULL)
        p = p->lchild;
    
    return p;
}

// function is for performing inorder traversals.
void BST :: Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }

};

// For searching in a binary search tree.
Node * BST ::Search(int key){
    Node* t = root;
    while(t!=NULL){
        if(t->data == key)
            return t;
        else if(t->data > key)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;

}

// This function will display the Height of the tree.
int BST ::Height(Node *root){
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


// A function for deleting the node.
Node * BST ::Delete(Node *p, int key){

    Node * q;

    if(p==NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == root)
            root = NULL;
        delete(p);
        return NULL;

    }    

    if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else{
        if(Height(p->lchild) > Height(p->rchild)){
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else{
            q = Insucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    BST bst;
    root = bst.RInsert(root, 10);
    bst.RInsert(root, 5);
    bst.RInsert(root, 20);
    bst.RInsert(root, 8);
    bst.RInsert(root, 30);

    bst.Inorder(root);
    cout << "\n";

    bst.Delete(root, 20);

    bst.Inorder(root);
    cout << "\n";
     

    return 0;
}