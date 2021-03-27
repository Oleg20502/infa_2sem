#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int *a = new int [N*N];
    int **matrix = new int *[N];
    for (int i=0; i<N;++i){
        matrix[i] = a + i*N;
    }
    for (int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            cin >> matrix[i][j];
        }
    }
    for (int j=0; j<N; ++j){
        for (int i=N-1; i>0; --i){
            cout << matrix[i][j] << ' ';
        }
        cout << matrix[0][j] << endl;
    }
    delete [] a;
    return 0;
}
