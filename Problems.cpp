#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    int a;
    cin >> a;
    v.erase(v.begin()+a - 1);
    for(int i=0; i < v.size(); i++)
      cout << v.at(i) << ' ';
    
    int s, e;
    cin >> s >> e;
    v.erase(v.begin()+s-1,v.begin()+e - 1);
    cout << v.size() << "\n";
    
    for(int i=0; i < v.size(); i++)
        cout << v.at(i) << ' ';
    return 0;
}
