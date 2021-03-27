#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x;
    cin >> x;
    if ((x == b - a) && (x == d/c)){
        cout << 5;
    }
    else if((x == b - a) || (x == d/c)){
        cout << 4;
    }
    else if(x == 1024){
        cout << 3;
    }
    else{
        cout << 2;
    }
    return 0;
}
