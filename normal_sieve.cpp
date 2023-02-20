#include <iostream>
#include <cmath>
using namespace std;

void PrimeSieve(int n){

    //Declaring the array
    bool prime[1000000];

    //Setting all the elements in the boolean array to true.
    for(int i=2; i<n; i++)
        prime[i] = true;

    // Marking the prime index in the array.
    for(int i=2; i*i<n; i++){
        if(prime[i] == true){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }

    // printing all the elements till n which are prime.
    for(int i=2; i<=n; i++){
        if(prime[i] == true)
            cout << i << " ";
    }
    cout << endl;

}

int main()
{
    int n;
    cin >> n;

    PrimeSieve(n);

  return 0;
}
