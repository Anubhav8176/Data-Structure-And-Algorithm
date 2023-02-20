#include <iostream>
using namespace std;

int main(){
    int number, position;
    cin >> number >> position;
    int bitMask = (1<<position);
    int finalresult = (bitMask & number);
    if(finalresult == 0)
        cout << "The bit is 0" << endl;
    else
        cout << "The bit is 1" << endl;

    return 0;
}
