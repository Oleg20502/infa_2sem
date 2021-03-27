#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double a;
    double s = 0, s_sq = 0;
    int N = 0;
    cin >> a;
    while (a != 0){
        s += a;
        s_sq += a * a;
        N += 1;
        cin >> a;
    }
    double M = s / N;
    double D = s_sq / N - M * M;
    cout.precision(1);
    cout << std::fixed << M << ' ' << D << endl;
    return 0;
}
