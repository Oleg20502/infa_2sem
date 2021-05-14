#include <iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
int n;
cin » n;
vector<vector<long long» dp(n, vector<long long>(3));
dp[0][0] = 1;
dp[0][1] = 1;
dp[0][2] = 1;
for (int i = 1; i < n; ++i) {
dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
dp[i][2] = dp[i][1] + dp[i - 1][1];
dp[i][0] %= 2147483647;
dp[i][1] %= 2147483647;
dp[i][2] %= 2147483647;
}
cout « (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2])% 2147483647;
return 0;
}
