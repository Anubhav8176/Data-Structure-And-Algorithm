#include <bits/stdc++.h>
using namespace std;

// Both Struct and Class will work almost same only syntax will be changed.
/*struct Node
{
  int data;
  Node *next;
};*/

/*data is used to store any element in a node, *next is a pointer used to point
on the next node of the linked list.*/
class Node
{
public:
  int data;
  Node *next;

  // All the operations are performed by following functions.
  void Create(int A[], int n);
  void Create2(int A[], int n);
  void Display(Node *p);
  int Counting(Node *p);
  int add(Node *p);
  int Max(Node *p);
  Node *Search(Node *p, int key);
  void FirstInsert(Node *p, int n);
  void MiddleInsert(Node *p, int pos, int n);
  void Insert(Node *p, int pos, int n);
  void Insertsorted(Node *p, int n);
  int Deletion(Node *p, int pos);
  bool CheckSorted(Node *t);
  void Removeduplicate(Node *p);
  void Reverse1(Node *p);
  void Reverse2(Node *p);
  void Reverse3(Node *p, Node *q);
  void Concatination(Node *p, Node *q);
  void merge(Node *p, Node *q);
  int isloop(Node *f);
} *first = NULL, *second = NULL, *third = NULL;
//first is used to point on first element of the linked list.

//pointer "t" will be used to create new node in the linked list.
//pointer "last" is used to add a node at the end of linked list. And it points
// at the last node of the linked list.

/*************
Process of creating a linked list include followig steps:-
STEP 1: We create first node and made it equal to last.
STEP 2: Then we create the new node named "t".
STEP 3: We assign the values of t to last and then first points on t.
*/
// This fnction will create a linked list.
void Node ::Create(int A[], int n)
{
  Node *t, *last;
  first = new Node; //this will create a new node everytime.
  first->data = A[0];
  first->next = NULL;
  last = first; /*Now the first node is created and the last pointer is pointing
  on the first node*/
  // This for loop will assign the value of each element array to the linked list.
  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

// This will create another Linked List pointed by second.
void Node ::Create2(int A[], int n)
{
  Node *t, *last;
  second = new Node; 
  second->data = A[0];
  second->next = NULL;
  last = second; 
  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void Node ::Display(Node *p)
{
  // PRINTING THE LINKED LIST VIA ITERATION.
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
  /* PRINTING THE LINKED LIST VIA RECURRSION.*/
  // if (p != NULL)
  // {
  //   // Display(p->next); /* Prints the linked lid=st in reverse.*/
  //   cout << p->data << " ";
  //   Display(p->next);
  // }
}

int Node ::Counting(Node *p)
{
  // COUNTING NO. OF ELEMENTS BY ITERATION.
  /*int count = 0;
  while (p != 0)
  {
    count++;
    p = p->next;
  }
  return count;*/
  // COUNTING NO. OF ELEMENT BY RECURRSION.
  if (p != NULL)
  {
    return 1 + Counting(p->next);
  }
  else
  {
    return 0;
  }
}

int Node ::add(Node *p)
{
  // ADDING BY ITERATION.
  /*int sum = 0;
  while (p != NULL)
  {
    sum = sum + p->data;
    p = p->next;
  }
  return sum;*/

  // ADDING BY RECURRSION.
  if (p != NULL)
  {
    return p->data + add(p->next);
  }
  else
  {
    return 0;
  }
}

int Node ::Max(Node *p)
{
  // FINDING THE MAXIMUM NUMBER BY ITERATION.
  /*int max = -32768;
  while (p != 0)
  {
    if (p->data > max)
    {
      max = p->data;
      p->next;
    }
    else
    {
      p = p->next;
    }
  }
  return max;*/

  // FINDING THE MAXIMUM NUMBER BY RECURRSION.
  int x;
  if (p == NULL)
  {
    return INT_MIN;
  }
  else
  {
    x = Max(p->next);
    if (x > p->data)
    {
      return Max(p->next);
    }
    else
    {
      return p->data;
    }
  }
}

Node *Node ::Search(Node *p, int key)
{
  // SEARCHING BY ITERATION.
  /*while (p != NULL)
  {
    if (key == p->data)
    {
      return p;
    }
    else
    {
  n     p = p->next;
    }
  }
  return NULL;*/

  // SEARCHING BY RECURRSION.
  if (p == NULL)
  {
    return NULL;
  }
  else if (key == p->data)
  {
    return p;
  }
  else
  {
    return Search(p->next, key);
  }
}

// This function will be used for inserting the new node in a linked list.
void Node ::FirstInsert(Node *p, int n)
{
  Node *t = new Node;
  t->data = n;
  t->next = first;
  first = t;
}

// This function will be ue=sed to insert any element in middle of Linked Lists.
void Node ::MiddleInsert(Node *p, int pos, int n)
{
  Node *t = new Node;
  t->data = n;
  p = first;
  for (int i = 0; i < pos - 1; i++)
  {
    p = p->next;
  }
  t->next = p->next;
  p->next = t;
}

// This function will be used at any particular position in the Linked Lists.
void Node ::Insert(Node *p, int pos, int n)
{
  if ((pos < 0) || (pos > Counting(p)))
  {
    exit;
  }
  else
  {
    Node *t = new Node;
    t->data = n;
    if (pos == 0)
    {
      t->next = first;
      first = t;
    }
    else
    {
      // p = first;
      for (int i = 0; i < pos - 1; i++)
      {
        p = p->next;
      }
      t->next = p->next;
      p->next = t;
    }
  }
}

// This function insert the element in s sorted linked List.
void Node ::Insertsorted(Node *p, int n)
{
  Node *t = new Node;
  Node *q;
  q = NULL;
  t->data = n;
  t->next = NULL;
  if (first == NULL)
  {
    first = t;
  }
  else
  {
    // p = first;
    while ((p != NULL) && (p->data < n))
    {
      q = p;
      p = p->next;
    };
    if (p == first)
    {
      t->next = first;
      first = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
    }
  }
}

// This function will delete any element at any index in Linked List.
int Node ::Deletion(Node *p, int index)
{
  Node *q;
  int x = -1;
  if ((index < 1) || (index > Counting(p)))
    return x;
  if (index == 1)
  {
    q = first;
    first = q->next;
    x = q->data;
    delete q;
    return x;
  }
  else
  {
    for (int i = 0; i < (index - 1); i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
    return x;
  }
}

// This function is used to check that the list is sorted or not.
bool Node ::CheckSorted(Node *t)
{
  int x = INT8_MIN;
  Node *p = first;
  while (p != NULL)
  {
    if (p->data < x)
      return false;
    else
    {
      x = p->data;
      p = p->next;
    }
  }
  return true;
}

//This function will remove the duplicate nodes.
void Node ::Removeduplicate(Node *t)
{
  Node *p;
  Node *q;
  p = first;
  q = p->next;
  while(q != NULL){
    if(p->data != q->data){
      p = q;
      q = q->next;
    }
    else{
      p->next = q->next;
      delete q;
      q = p->next;
    }
  }
}

// This function will Reverse the elements in a linked lis by using a array.
void Node :: Reverse1(Node *p){
  int A[Counting(p)];
  p = first;
  int i = 0;
  while(p != NULL){
    A[i] = p->data;
    p = p->next;
    i++;
  }
  p = first;
  i--;
  while(p != NULL){
    p->data = A[i];
    i--;
    p = p->next;
  }
}

// This function will reverse the Linked List by changing the Linkage of nodes.
void Node :: Reverse2(Node *p){
  p = first;
  Node *q = NULL;
  Node *r = NULL;
  while(p != NULL){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

// This function will reverse the Linked List by using Recurrsion.
void Node :: Reverse3(Node *q, Node *p){
  if(p != NULL){
    Reverse3(p, p->next);
    p->next = q;
  }
  else
    first = q;
}

// This function will help in cocatinating the two Linked Lists.
void Node :: Concatination(Node *p, Node *q){
  third = p;
  while(p->next != NULL){
    p = p->next;
  }
  p->next = q;
}

// This function will merge two linked list.
void Node :: merge(Node *p, Node *q){
  Node *last;
  if(p->data < q->data){
    third = last = p;
    p = p->next;
    third->next = NULL;
  }
  else{
    third = last = q;
    q = q->next;
    third->next = NULL;
  }
  while((p != NULL) && (q != NULL)){
    if(p->data < q->data){
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    }
    else{
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }
  if(p != NULL)
    last->next = p;
  
  if(q != NULL)
    last->next = q;
}

// This function will to check weather the list is in loop or linear.
int Node :: isloop(Node *f){
  Node *p, *q;
  p = q = f;
  do{
      p = p->next;
      q = q->next;
      q = q!=NULL ? q->next : q;
  }while((p != NULL) && (q!= NULL) && (p != q));
  if(p == q)
    return 1;
  else
    return 0;  
}


int main()
{
  Node LinkedList;
  // Node *temp;
  int A[] = {10, 20, 30, 40, 50};
  LinkedList.Create(A, 5); 
  // LinkedList.Display(first);
  // cout << endl;
  // cout << "No. of Nodes are " << LinkedList.Counting(first) << endl;
  // cout << "Addition of the data stored is " << LinkedList.add(first) << endl;
  // cout << "Maximum among the give data is " << LinkedList.Max(first) << endl;
  // cout << LinkedList.Search(first, 10) << endl;
  // temp = LinkedList.Search(first, 17);
  // LinkedList.FirstInsert(first, 9);
  // LinkedList.Insertsorted(first, 55);
  // LinkedList.Insertsorted(first, 25);
  // cout << LinkedList.Deletion(first, 100) << endl;
  // LinkedList.Removeduplicate(first);
  // LinkedList.Reverse3(NULL, first) ;
  // LinkedList.merge(second,first);
  // Node *temp, *temp1;
  // temp = first->next->next;
  // temp1 = first->next->next->next->next;
  // temp1->next = temp;

  int a = LinkedList.isloop(first);
  if(a == 1)
    cout << "The List is looped" << endl;
  else if(a == 0)
    cout << "The loop is not looped" << endl;

  return 0;
}