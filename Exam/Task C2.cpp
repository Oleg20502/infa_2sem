#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct Abonent{
    string name;
    string number;
    long int balance;
};

bool compute(Abonent a, Abonent b){
    if (a.balance != b.balance){
            return a.balance > b.balance;
    }
    else{
        if (a.name != b.name){
            return a.name < b.name;
        }
        else{
                return a.number < b.number;
        }
    }
}

int main()
{
    int n, i;
    cin >> n;
    vector<Abonent> abonents(n);
    for (i = 0; i < n; ++i){
        cin >> abonents[i].name >> abonents[i].number >> abonents[i].balance;
    }
    sort(abonents.begin(), abonents.end(), compute);
    for (i = 0; i < min(n, 10); ++i){
        cout << abonents[i].name << " " << abonents[i].number << " " << abonents[i].balance << endl;
    }
    return 0;
}

