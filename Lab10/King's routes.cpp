#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 8, m = 8;
    vector<vector<int>> d(n, vector<int>(m, 1));
    for (int i=1; i<n; ++i){
        for (int j=1; j<m; ++j){
            d[i][j] = d[i-1][j]+d[i][j-1];
        }
    }

    return 0;
}
