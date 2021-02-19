#include <iostream>

using namespace std;

int main()
{
    int s = 0, n, mean;
    cin >> n;
    int *array = new int [n];

    for (int i=0; i<n; ++i){
        cin >> array[i];
    }
    for (int i=0; i<n; i++){
        s += array[i];
    }
    mean = s / n;
    s = 0;
    for (int i=0; i<n; i++){
        if (array[i] > mean){
            s += array[i];
        }
    }
    cout << s;
    return 0;
}
