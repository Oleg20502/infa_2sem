#include <iostream>
using namespace std;

int main()
{
    int nmax = 0, a;
    cin >> a;
    if (a % 2 == 0){
        nmax = a;
    }
    while (a != 0){
        if (a % 2 == 0 and a > nmax){
            nmax = a;
        }
        cin >> a;
    }
    cout << nmax;
    return 0;
}

