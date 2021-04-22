#include <iostream>
#include <vector>

using namespace std;

unsigned long long power(unsigned a,  unsigned n)
{
    if (n==0) return 1;
    if (n%2==0){
        unsigned long long x = power(a, n/2);
        return x*x;
    }
    return a * power(a, n-1);
}

unsigned long long power_cycle(unsigned a,  unsigned n)
{
    vector<bool> stack;
    while(n){
        if(n%2==0){
            stack.push_back(true);
            n /=2;
        }
        else{
            stack.push_back(false);
            n -=1;
        }
    }
    unsigned long long result = 1;

    while(!stack.empty()){
        if (stack.back()){
            result *= result;
        }
        else{
            result *= a;
        }
        stack.pop_back();
    }
    return result;
}

int main()
{

    return 0;
}
