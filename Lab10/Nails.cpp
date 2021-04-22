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



    return 0;
}
