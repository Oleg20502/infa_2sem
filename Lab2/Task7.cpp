#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, c = 1;
    cin >> a;
    for (int i = 2; i <= sqrt(a+2); i++){
        if (a % i == 0){
            c = 0;
        }
    }
    cout << c;
    return 0;
}
