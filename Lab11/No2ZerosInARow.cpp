#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long int> d(N, 0);
    d[0] = K-1;
    d[1] = K * d[0];
    for (int i=2; i<N; ++i){
        d[i] = (K-1)*(d[i-1] + d[i-2]);
    }
    cout << d[N-1] << '\n';
    return 0;
}
