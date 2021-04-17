#include <iostream>

using namespace std;

double outcome(int n)
{
    if (n > 1){
        return 70.0 + 1.4 * outcome(n-1);
    }
    else if (n = 1){
        return 70.0;
    }
}

double income(int n)
{
    if (n > 1){
        return 40.0 + 0.6 * outcome(n-1);
    }
    else if (n = 1){
        return 40.0;
    }
}

int main()
{
    int N;
    cin >> N;
    cout << static_cast<int64_t>(income(N));
    return 0;
}
