#include <iostream>
using namespace std;

class Matrix
{
  int *A;
  int n;
public:
  Matrix()
  {
    n = 2;
    A = new int[2];
  }
  Matrix(int b)
  {
    n = b;
    A = new int[n];
  }
  void Display();
  void Displaylowertriangle();
  void DisplayUppertriangle();
  void Displaysymmetric();
  void Displaytridiagonal();
  void SetDiagonal(int i, int j, int x);
  int GetDiagonal(int i, int j);
  void Setlowertriangle(int i, int j, int x);
  int Getlowertriangle(int i, int j);
  void Setuppertriangle(int i, int j, int x);
  int Getuppertriangle(int i, int j);
  void Setsymmetric(int i, int j, int x);
  int Getsymmetric(int i, int j);
  void Settridiagonal(int i, int j, int x);

};

void Matrix :: Display()
{
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
          cout << A[i - 1] << " ";
      }
      else {
        cout << "0 " ;
      }
    }
    cout << endl;
  }
}

void Matrix :: SetDiagonal(int i, int j, int x)
{
  if (i == j) {
    A[i - 1] = x;
  }
}

int Matrix :: GetDiagonal(int i, int j)
{
  if (i == j) {
    return A[i - 1];
  }
  else {
    return 0;
  }
}

void Matrix :: Setlowertriangle(int i, int j, int x)
{
  if (i >= j) {
    A[i*(i - 1)/2 + j - 1] = x;
  }
}

int Matrix :: Getlowertriangle(int i, int j)
{
    if (i >= j) {
      return A[i*(i - 1)/2 + j - 1];
    }
    else
    {
      return 0;
    }
}

void Matrix :: Displaylowertriangle()
{
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= j) {
          cout << A[i*(i - 1)/2 + j - 1] << " ";
      }
      else {
        cout << "0 " ;
      }
    }
    cout << endl;
  }
}

void Matrix :: Setuppertriangle(int i, int j, int x)
{
  if (i <= j) {
    A[j*(j - 1)/2 + i - 1] = x;
  }
}

int Matrix :: Getuppertriangle(int i, int j)
{
    if (i <= j) {
      return A[j*(j - 1)/2 + i - 1];
    }
    else
    {
      return 0;
    }
}

void Matrix :: DisplayUppertriangle()
{
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i <= j) {
          cout << A[j*(j - 1)/2 + i - 1] << " ";
      }
      else {
        cout << "0 " ;
      }
    }
    cout << endl;
  }
}

void Matrix :: Setsymmetric(int i, int j, int x)
{
  if (i <= j) {
    A[j*(j - 1)/2 + i - 1] = x;
  }
  if (i > j) {
    A[n*(j - 1) - (j - 2)*(j - 1)/2 + (i - j)] = A[j*(j - 1)/2 + i - 1];
  }
}

int Matrix :: Getsymmetric(int i, int j)
{
    if (i <= j) {
      return A[j*(j - 1)/2 + i - 1];
    }
    if (i > j) {
      return A[i*(i - 1)/2 + j - 1];
    }
    else{
      return 0;
    }
}

void Matrix :: Displaysymmetric()
{
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i <= j) {
          cout << A[j*(j - 1)/2 + i - 1] << " ";
      }
      if (i > j) {
         cout << A[i*(i - 1)/2 + j - 1] << " ";
      }
    }
      cout << endl;
  }
}

void Matrix :: Settridiagonal(int i, int j, int x)
{
  if (i > j) {
    A[i - 2] = x;
  }
  else if (i == j) {
    A[n + i - 2] = x;
  }
  else if (i < j) {
    A[2*n + i - 2] = x;
  }
}

void Matrix :: Displaytridiagonal()
{
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i - j) == 1) {
          cout << A[i - 2] << " ";
      }
      if ((i - j) == 0) {
         cout << A[n + i - 2] << " ";
      }
      if ((i - j) == -1) {
        cout << A[2*n + i - 2] << " ";
      }
      else
      {
        cout << 0 << " " ;
      }
    }
      cout << endl;
  }
}


int main()
{
  int a , x;
  cout << "Enter the dimension of Matrix-> " << flush;
  cin >> a;
  Matrix tridiagonal(a);
  cout << "Enter the matrix here:- " << endl;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= a; j++) {
      cin >> x;
      tridiagonal.Settridiagonal(i, j, x);
    }
    cout << endl;
  }
  cout << endl;
  tridiagonal.Displaytridiagonal();
  cout << "The dimension of the above matrix is " << a << endl;
  return 0;

}
