#include <iostream>
using namespace std;

// Function for Swapping the elements.
void Swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function for merging the elements of two arrays.
void merge(int A[], int l, int mid, int h){
    int i = l, j = mid+1, k = l;
    int B[(l+h)*2];
    while(i<=mid && j<=h){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(;i<=mid; i++)
        B[k++] = A[i];
    for(;j<=h; j++)
        B[k++] = A[j];
    
    for(i=l; i<=h; i++)
        A[i] = B[i];
}

//Function to find the maximum number in the whole array.
int findMax(int A[], int n){
    int num =0;
    for(int i=0; i<n; i++){
        if(A[i] > num)
            num = A[i];
    }
    return num;
}

void BubbleSort(int A[], int n){
    int flag=0;
    for(int i = 0; i<(n-1); i++){
        for(int j = 0; j<(n-1-i); j++){
            if(A[j] > A[j+1]){
                Swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag==0)
            return;        
    }
}

void InsertionSort(int A[], int n){
    for(int i = 0; i<n; i++){
        int j = i-1;
        int x = A[i];
        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void SelectionSort(int A[], int n){
    for(int i=0; i<(n-1); i++){
        int j, k;
        for(j = k = i; j<n; j++){
            if(A[j]<A[k])
                k=j;
        }
        Swap(&A[i], &A[k]);
    }
}

void IMergeSort(int A[], int n){
    int p, i, l, mid, h;
    for(p = 2; p<=n; p=p*2){
        for(i=0; i+p-1<n; i=i+p){
            l=i;
            h=i+p-1;
            mid = (l+h)/2;
            merge(A,l,mid,h);
        }
        if(n-i>p/2){ 
            l = i; 
            h = i+p-1; 
            mid = (l+h)/2; 
            merge(A, l, mid, n-1); 
        }
    }
    if(p/2 < n)
        merge(A,0,p/2-1,n-1);
}

void CountSort(int A[], int n){
    int max;
    int *c;
    max = findMax(A,n);
    c = new int[max+1];
    for(int i=0; i<max+1; i++){
        c[i]=0;
    }
    for(int i=0; i<n; i++){
        c[A[i]]++;
    }
    int i=0,j=0;
    while(i<(max+1)){
        if(c[i]>0){
            A[j++]=i;
            c[i]--;
        }
        else
            i++;
    }
}

void ShellSort(int A[], int n){
    for (int gap=n/2; gap>=1; gap/=2){
        for (int j=gap; j<n; j++){
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp){
                A[i+gap] = A[i];
                i = i-gap;
            }
            A[i+gap] = temp;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i<n; i++){
        cin >> A[i];
    }
    ShellSort(A,n);
    for(int i = 0; i<n; i++){
        cout << A[i] << " ";
    }

    return 0;
}