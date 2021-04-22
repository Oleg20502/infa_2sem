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

int main()
{
    int W, N;
    cin >> W >> N;
    vector<vector<int>> items(2, vector<int> (N, 0));
    for (int i=0; i<2; ++i){
        for (int j=0; j<N; ++j){
            cin >> items[i][j];
        }
    }
    vector<vector<int>> d(W+1, vector<int>(N+1, 0));

    for (int i=1; i<=W; ++i){
        for (int j=1; j<=N; ++j){
            if (i >= items[1][j-1]){
                d[i][j] = max(d[i][j-1], d[i-items[1][j-1]][j-1]+items[0][j-1]);
            }
            else d[i][j] = d[i][j-1];
        }
    }
    cout << d[W][N] << '\n';
    return 0;
}
