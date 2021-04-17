#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int s = 0;
    for (int i=0; i<str.length(); ++i){
        if (str[i] == ' '){
            ++s;
        }
    }
    if (str != "")
        ++s;
    cout << s;
    return 0;
}
