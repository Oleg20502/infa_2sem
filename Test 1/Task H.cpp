#include <iostream>

using namespace std;

int bin_find(int k, int* arr, int a, int b)
{
    int i = (b+a)/2;
    if (b-a == 0 && arr[i] != k){
        return -1;
    }
    else if (b-a == 0 || arr[i] == k){
        return 1+i;
    }
    else if(arr[i] < k)
        return bin_find(k, arr, i+1, b);
    else
        return bin_find(k, arr, 0, i-1);
}

int main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    int* arr = new int [N];
    for (int i = 0; i<N; ++i){
        cin >> arr[i];
    }
    cout << bin_find(K, arr, 0, N-1);
    delete [] arr;
    return 0;
}
