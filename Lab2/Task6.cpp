#include <iostream>
using namespace std;

int main()
{
    int nmax, nummax = 1, a;
    cin >> a;
    nmax = a;
    while (a != 0){
        cin >> a;
        if (a == nmax){
            nummax++;
        }
        else if (a > nmax){
            nmax = a;
            nummax = 1;
        }
    }
    cout << nummax;
    return 0;
}
