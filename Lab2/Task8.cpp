#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, i = 2, stop;
    cin >> a;
    stop = sqrt(a+2);
    while (i <= stop){
        if (a % i == 0){
            cout << i << endl;
            a /= i;
        }
        else{
            i++;
        }
    }
    return 0;
}

