#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int j = 0;
    int d = (int)'a'-(int)'A';
    for (int i=0; i<str.length(); ++i){
        if (str[i] != ' '){
            if (j%2 == 0 && str[i] > 96){
                str[i] = (char)((int)str[i] - d);
            }
            else if (j%2 == 1 && str[i] < 96){
                str[i] = (char)((int)str[i] + d);
            }
            ++j;
        }
    }
    cout << str;
    return 0;
}
