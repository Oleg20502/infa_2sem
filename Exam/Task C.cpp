#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> names;
    vector<string> numbers;
    vector<long long int> balance;
    string name, number;
    long long int sum;
    for (int i=0; i<N; ++i){
        cin >> name >> number >> sum;
        if (sum < 0){
            names.push_back(name);
            numbers.push_back(number);
            balance.push_back(sum);
        }
    }
    int n = balance.size();
    for (int i=1; i<n; ++i){
        for (int j=i; j>0 ;--j){
            if (balance[j] < balance[j-1]){
                swap(balance[j], balance[j-1]);
                swap(names[j], names[j-1]);
                swap(numbers[j], numbers[j-1]);
            }
        }
    }
    int k = 100;
    if (n < 100) k = n;
    for (int i=0; i<k; ++i){
        cout << names[i] <<' ' << numbers[i] <<' '<<balance[i] <<'\n';
    }
    return 0;
}
