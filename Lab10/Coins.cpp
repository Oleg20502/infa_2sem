#include <iostream>
#include <vector>
//#define INT_MAX

using namespace std;

/*void print_array(vector<vector<int>> arr, int N, int M)
{
    for (int i=1; i<=N; ++i){
        for (int j=1; j<=M; ++j){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}*/

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

int main()
{
    int N, S;
    cin >> S >> N;
    int* coins = new int [N];
    for (int i=0; i<N; ++i){
        cin >> coins[i];
    }
    vector<vector<int>> d(S+1, vector<int>(N+1, 0));
    for (int i=1; i<=S; ++i){
        d[i][0] = S + 10 * coins[0];
    }
     for (int i=1; i<=S; ++i){
        for (int j=1; j<=N; ++j){
            if (i >= coins[j-1]){
                d[i][j] = min(d[i][j-1], d[i-coins[j-1]][j]+1);
            }
            else d[i][j] = d[i][j-1];
        }
    }

    cout << d[S][N] << '\n';
    return 0;
}

