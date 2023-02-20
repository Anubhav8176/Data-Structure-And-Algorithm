#include <bits/stdc++.h>
using namespace std;

// Declaring the array
const int N = 1000000;
bool sieve[N + 1];

void CreateSieve(){

    // Setting all the elements in the boolean array to true.
    for (int i = 2; i <= N; i++)
        sieve[i] = true;

    // Marking the prime index in the array.
    for (int i = 2; i * i < N; i++){
        if (sieve[i] == true){
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }
}

vector<int> generatePrime(int N){
    vector<int> ds;
    for (int i = 2; i <= N; i++){
        if (sieve[i] == true)
            ds.push_back(i);
    }
    return ds;
}

int main(){

    CreateSieve();
    int t;
    cin >> t;
    while (t--){
        int l, r;
        cin >> l >> r;

        // Step 1:- Generating all the Primes til <=sqrt(upper_limit).
        vector<int> primes = generatePrime(sqrt(r));
        // for(int pr: primes)
            // cout << pr << " ";

        // r = upper_limit, l = lower_limit.
        // Create a dummy array of size (r - l + 1) and mark that with one
        bool dummy_array[r - l + 1];
        for (int i = 0; i<(r-l+1); i++)
            dummy_array[i] = true;

        // Step 3: Marking all multiples of primes in (l - r) in dummy array.
        for (auto pr : primes){

            int firstmultiple = (l / pr) * pr;
            if (firstmultiple < l)
                firstmultiple += pr;
                // cout << firstmultiple << endl;
            for (int j = max(firstmultiple, pr * pr); j <= r; j += pr)
                dummy_array[j - l] = false;
        }

        // Step 4: Printing all the multiples in thye given range.
        for (int i = l; i <= r; i++){
            if(dummy_array[i - l] == true)
                cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
