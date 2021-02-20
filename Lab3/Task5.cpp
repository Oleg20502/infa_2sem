#include <iostream>

using namespace std;

int do_some_awesome_work(int* a, int* b);

int main()
{
    int a, b;
    cin >> a >> b;
    int* Pa = &a;
    int* Pb = &b;
    cout << do_some_awesome_work(Pa, Pb);
    return 0;
}

int do_some_awesome_work(int* a, int* b)
{
    return *a+*b;
}
