#include <iostream>
#include <string>

using namespace std;

int main()
{
    int max = -1;
    string str;
    getline(cin, str);
    int p = 0;
    int a = 0;
    for (int i=0; i<str.length(); ++i){
        if ('0' <= str[i] &&  str[i] <= '9'){
            if (p == 0){
                p = 1;
                a = (int)str[i] - (int)'0';
            }
            else{
                a *= 10;
                a += (int)str[i] - (int)'0';
            }
        }
        else if (p == 1){
            if (a > max)
                max = a;
            p = 0;
            a = 0;
        }
    }
    if (p == 1){
        if (a > max)
            max = a;
    }
    cout << max;
    return 0;
}
