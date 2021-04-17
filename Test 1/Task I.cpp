#include <iostream>

using namespace std;

void insertion_sort_modified(int* arr1, int* arr2, int N)
{
    int a;
    for (int i=1; i<N; ++i){
        for (int j=i; j>0 ;--j){
            if (arr1[j] < arr1[j-1]){
                /*a = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = a;*/
                swap(arr1[j], arr1[j-1]);
                swap(arr2[j], arr2[j-1]);
            }
            else if(arr1[j] == arr1[j-1]){
                if (arr2[j] < arr2[j-1]){
                    swap(arr1[j], arr1[j-1]);
                    swap(arr2[j], arr2[j-1]);
                }
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int* arr1 = new int [N];
    int* arr2 = new int [N];
    for (int i = 0; i<N; ++i){
        cin >> arr1[i];
    }
    for (int i = 0; i<N; ++i){
        cin >> arr2[i];
    }

    insertion_sort_modified(arr1, arr2, N);

    for (int i = 0; i<N-1; ++i){
        cout << arr1[i] << ' ';
    }
    cout << arr1[N-1] << '\n';
    for (int i = 0; i<N-1; ++i){
         cout << arr2[i] << ' ';
    }
    cout << arr2[N-1];
    delete [] arr1;
    delete [] arr2;
    return 0;
}
