#include <iostream>
using namespace std;

int main()
{
    int i = 0, a;
    cin >> a;
    while (a != 0){
        if (a % 2 == 0){
            i++;
        }
        cin >> a;
    }
    cout << i;
    return 0;
}
