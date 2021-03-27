#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int N;
    cin >> N;
    int a;
    int s = 0;
    for (int i=0; i<N; ++i){
        cin >> a;
        if(a % 4 == 0){
            if((a/1000 != 4) && (a/1000 != 5)){
                s = 1;
                cout << a << endl;
                continue;
            }
        }
        if(a % 7 == 0){
            if((a/1000 != 1) && (a/1000 != 7)){
                s = 1;
                cout << a << endl;
                continue;
            }
        }
        if(a % 9 == 0){
            if((a/1000 != 8) && (a/1000 != 9)){
                s = 1;
                cout << a << endl;
                continue;
            }
        }
    }
    if (s == 0){
        cout << 0;
    }
    return 0;
}
