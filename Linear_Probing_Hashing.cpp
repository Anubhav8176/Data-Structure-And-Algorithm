#include <iostream>
#define SIZE 10
using namespace std;

int Hash(int key){
    return key%10;
}

int LinearProbe(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while(H[(idx+i)%SIZE] != 0){
        i++;
    }
    return (idx+i)%SIZE;
}

void Insert(int H[], int key){
    int idx = Hash(key);
    if(H[idx] != 0){
        idx = LinearProbe(H, key);
    }
    H[idx] = key;
}
 
int Search(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i) % SIZE] != key){
        i++;
        if (H[(idx + i) % SIZE] == 0){
            return -1;
        }
    }
    return (idx + i) % SIZE;
}

void print(int H[], int n){
    for(int i=0; i<n; i++){
        cout << H[i] << " ";
    }
    cout << "\n";
}

int main(){
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);
    print(A, n);    
 
    // Hash Table
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }
    print(HT, n+1);
    int key;
    cin >> key;
    if(Search(HT, key) != -1)
    cout << "The key "<<key<<" is present at position "<<Search(HT, key)<<"\n";
    else
    cout << "Key didnot found\n";

    return 0;
}