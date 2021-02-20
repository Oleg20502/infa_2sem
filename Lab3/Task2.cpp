#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int n, m, mines;
    cin >> n >> m >> mines;
    n += 2;
    m += 2;
    int* a = new int [n*m];
    int** field = new int *[n];
    for (int l = 0; l < n; ++l){
        field[l] = a + l*m;
    }
    int i, j;
    for (i = 1; i < n-1; ++i){
        for (j = 1; j < m-1; ++j){
            field[i][j] = 0;
        }
    }
    for (int k = 0; k < mines; ++k){
        cin >> i >> j;
        for (int f=0;f<9; ++f){
            if (field[i-1+f/3][j-1+f%3] != -1){
                ++field[i-1+f/3][j-1+f%3];
            }
        }
        field[i][j] = -1;
    }
    for (i = 1; i < n-1; ++i){
        for (j = 1; j < m-1; ++j){
            cout << field[i][j]<<' ';
        }
        cout << endl;
    }
    delete [] a;
    delete [] field;
    return 0;
}
