#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

vector<int> insertion_sort(vector<int> arr, int N)
{
    int a;
    for (int i=1; i<N; ++i){
        for (int j=i; j>0 ;--j){
            if (arr[j] < arr[j-1]){
                a = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = a;
            }
        }
    }
    return arr;
}

int main()
{
    int N;
    cin >> N;
    vector<int> nails(N, 0);
    for (int i=0; i<N; ++i){
        cin >> nails[i];
    }
    nails = insertion_sort(nails, N);
    vector<int> d(N-1, 0);
    d[0] = nails[1] - nails[0];
    d[1] = nails[2] - nails[0];
    for(int i=2; i<N-1; ++i){
        d[i] = min(d[i-1], d[i-2]) + nails[i+1] - nails[i];
    }
    cout << d[N-2];
    return 0;
}
