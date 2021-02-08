#include <iostream>
#include <string>

using namespace std;

int main()
{
    int speed = 0, wage;
    string n = "starto";
    while (n != "A999AA"){
        if (speed > 60){
            if (n[1] == n[2] and n[2]==n[3]){
                wage += 1000;
            }
            else if (n[1] != n[2] and n[2]!=n[3] and n[3]!=n[1]){
                wage += 100;
            }
            else{
                wage += 500;
            }
        }
        cin >> speed >> n;
    }
    cout << wage;
    return 0;
}
