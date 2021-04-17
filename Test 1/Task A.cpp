// A
#include <iostream>

using namespace std;

int main()
{
    int a;
    int s = 0;
    cin >> a;
    for (int i=0; i<3; ++i){
        s += a%10;
        a /= 10;
    }
    cout << s;
    return 0;
}
