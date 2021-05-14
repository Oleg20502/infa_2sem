#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main()
{
    int N;
    cin >> N;
    int a[N];
    int b[N];
    int f;
    for(int i=0; i<N; ++i){
        cin >> f;
        a[i] = f;
        cin >> f;
        b[i] = f;
    }
    for(int i=0; i<N; ++i){
        for(int j = 0; j<N; ++j){
            for( int c = 0; c<N; c++){
                if(a[i] == a[j]+a[c] && b[i] == b[j] + b[c] && i!=j && i!=c && j!=c){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
