#include <iostream>
#include <string>

using namespace std;

string make_str(string a, int b)
{
    string str = "";
    for (int i = 0; i < b; i++){
        str += a;
    }
    return str;
}

string vnum(int a)
{
    return make_str("<", a / 10) + make_str("v", a%10);
}

string encode(int n)
{
    if (n < 60){
        return vnum(n);
    }
    else{
        return encode(n/60) + "." + vnum(n%60);
    }
}

int main()
{
    int N;
    cin >> N;
    cout << encode(N);
    return 0;
}
