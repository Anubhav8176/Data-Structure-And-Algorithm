#include <iostream>
using namespace std;

int main()
{
  //Declaration and getting the array.
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  // Taking the first digit from every elemets for the first half.
  for (int i = 0; i < n / 2; i++)
  {
  label:
    if (A[i] > 9)
    {
      A[i] = A[i] / 10;
      goto label;
    }
    else
    {
      A[i] = A[i];
    }
  }

  // Taking the last digits from the next half.
  for (int i = (n / 2); i < n; i++)
  {
    A[i] = A[i] % 10;
  }

  // Merging the elements of arrays and creating a new integer.
  int finalNumber = 0;
  for (int i = 0; i < n; i++)
  {
    int num = A[i];
    if (num != 0)
    {
      while (num > 0)
      {
        finalNumber = finalNumber * 10;
        num = num / 10;
      }
      finalNumber = finalNumber + A[i];
    }
    else
    {
      finalNumber = finalNumber * 10;
    }
  }

  // Checking no. is divisble by 11 or not.
  if ((finalNumber % 11) == 0)
  {
    cout << "OUI" << endl;
  }
  else
  {
    cout << "NON" << endl;
  }

  return 0;
}