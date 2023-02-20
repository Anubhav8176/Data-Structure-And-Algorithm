#include <iostream>
#include <stdio.h>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }

    void Swap(int *x, int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    void Delete(int x);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    int Set(int index, int x);
    int max();
    int min();
    int sum();
    float Average();
    void Reverse();
    void LeftShift();
    void LeftRotate();
    void Insertsorted(int x);
    int Sorted();
    void Rearrange();
    Array* Merge(struct Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);
};

void Array ::Display()
{
    cout << "The elements of the array are as follows " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
}

void Array ::Append(int x)
{
    if (size > length)
    {
        A[length++] = x;
    }
}

void Array ::Insert(int index, int n)
{
    int i;
    length++;
    if (index >= 0 & index <= length)
    {
        for (i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[i] = n;
    }
}

void Array ::Delete(int x)
{
    if (x >= 0 & x <= length)
    {
        for (int i = x; i < length; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
}

int Array ::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            Swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

int Array ::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

/*int RBinSearch(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return RBinSearch(a, l, mid - 1, key);
        }
        else
        {
            return RBinSearch(a, mid + 1, h, key);
        }
    }
    return -1;
}*/

int Array ::Get(int index)
{
    if (index >= 0 & index < +length)
    {
        int i;
        i = A[index];
        return i;
    }
    else
    {
        return -1;
    }
}

int Array ::Set(int index, int x)
{
    if (index >= 0 & index <= length)
    {
        A[index] = x;
        return x;
    }
    else
    {
        return -1;
    }
}

int Array ::max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int Array ::min()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

int Array ::sum()
{
    int a = 0;
    for (int i = 0; i < length; i++)
    {
        a = a + A[i];
    }
    return a;
}

float Array ::Average()
{
    float a;
    a = sum() / length;
    return a;
}

void Array ::Reverse()
{
    int n = length;
    int i;
    for (i = 0; i < n / 2; i++)
    {
        int temp;
        temp = A[i];
        A[i] = A[(n - 1) - i];
        A[(n - 1) - i] = temp;
    }
}

void Array ::LeftShift()
{
    for (int i = 0; i < length; i++)
    {
        A[i] = A[i + 1];
    }
}

void Array ::LeftRotate()
{
    int temp = A[0];
    for (int i = 0; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = temp;
}

void Array ::Insertsorted(int x)
{
    int i = length - 1;
    if (length == size)
    {
        return;
    }
    else
    {
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
    }
    A[i + 1] = x;
    length++;
}

int Array ::Sorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void Array ::Rearrange()
{
    int i = 0;
    int j = length - 1;
    while (A[i] < 0)
        i++;
    while (A[i] >= 0)
        j++;
    if (i < j)
    {
        Swap(&A[i], &A[j]);
    }
}

Array* Array :: Merge(Array arr2)
{
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k] = A[i];
            k++;
            i++;
        }
        else
        {
            arr3->A[k] = arr2.A[j];
            k++;
            j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k] = A[i];
        k++;
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k] = arr2.A[j];
        k++;
    }
    arr3->length = length + arr2.length;

    return arr3;
}

Array* Array :: Union(Array arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 =new Array(length + arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k] = A[i];
            i++;
            k++;
        }
        else if (arr2.A[j] < A[i])
        {
            arr3->A[k] = arr2.A[j];
            j++;
            k++;
        }
        else
        {
            arr3->A[k] = A[i];
            i++;
            k++;
            j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k] = A[i];
        k++;
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k] = arr2.A[j];
        k++;
    }
    arr3->length = k;
    return arr3;
}

Array* Array :: Intersection(Array arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 =new Array(length + arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            i++;
        }
        else if (arr2.A[j] < A[i])
        {
            j++;
        }
        else if (arr2.A[j] == A[i])
        {
            arr3->A[k] = A[i];
            i++;
            k++;
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

Array* Array :: Difference(Array arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    Array *arr3 =new Array(length + arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k] = A[i];
            i++;
            k++;
        }
        else if (arr2.A[j] < A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k] = A[i];
        k++;
    }
    arr3->length = k;
    return arr3;
}

int main()
{
    int ch;
    Array arr;
    do
    {
        cout << "Menu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Sum" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;

        int x, index;
        cout << "Enter your choice " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the index and value " << endl;
            cin >> x >> index;
            arr.Insert(index, x);
            break;
        case 2:
            cout << "Enter the index " << endl;
            cin >> index;
            arr.Delete(index);
            break;
        case 3:
            cout << "Enter the element:-" << endl;
            cin >> x;
            arr.LinearSearch(x);
            break;
        case 4:
            cout << "Sum is " << (arr.sum()) << endl;
            break;
        case 5:
            arr.Display();
        }
    } while (ch < 6);

    return 0;
}
