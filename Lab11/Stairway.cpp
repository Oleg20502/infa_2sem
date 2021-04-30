#include <iostream>
#include <vector>

using namespace std;

void print_array(vector<int> arr, int N)
{
    for (int i=0; i<N-1; ++i){
        cout << arr[i] << ' ';

    }
    cout << arr[N-1] << '\n';
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int main()
{
    int N;
    cin >> N;
    vector<int> numbers(N, 0);
    for(int i=0; i<N; ++i){
        cin >> numbers[i];
    }
    vector<int> stairs;
    vector<int> d(N, 0);
    d[0] = numbers[0];
    if (numbers[1] > numbers[1]+numbers[0]){
        d[1] = numbers[1];
    }
    else{
        d[1] = numbers[1] + numbers[0];
    }

    for(int i=2; i<N; ++i){
        if (d[i-1] > d[i-2]){
            d[i] = d[i-1];
            stairs.push_back(i);
        }
        else{
            d[i] = d[i-2];
            if (stairs.size() != 0){
                if (stairs.back() == i-1){
                    stairs.pop_back();
                }
            }
            stairs.push_back(i-1);
        }
        d[i] += numbers[i];
    }
    stairs.push_back(N);
    cout << d[N-1] << '\n';
    print_array(stairs, stairs.size());
    return 0;
}
