#include <iostream>
using namespace std;

int main()
{
    int n, r = 0;
    cin >> n;
    while (n != 1){
        r += n % 2;
        n /= 2;
        //cout << n<<endl;
    }
    if (r == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
