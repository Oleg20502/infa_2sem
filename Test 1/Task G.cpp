#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int* arr = new int [N];
    for (int i = 0; i<N; ++i){
        cin >> arr[i];
    }
    for (int i = N-1; i>0; --i){
        cout << arr[i] << ' ';
    }
    cout << arr[0];
    delete [] arr;
    return 0;
}
