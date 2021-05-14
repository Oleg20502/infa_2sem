#include <iostream>
#include <map>
#include <string>


using namespace std;


int main()
{
    size_t n;
    cin >> n;
    string name, number;
    int32_t balance;
    map<int32_t, string> m;
    for (int i = 0; i<n; ++i){
        cin >> name >> number >> balance;
        m[balance] = name + " " + number;
    }
    auto Current = m.begin();
    for (int i = 0; i<100; ++i){
        if (Current->first >= 0){
            break;
        }
        cout << Current->second << " " << Current->first << endl;
        Current++;
    }
    return 0;
}
