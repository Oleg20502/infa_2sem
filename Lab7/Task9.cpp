#include <iostream>
#include <string>

using namespace std;

int pow(int a, int p)
{
    if (p > 0) return a*pow(a, p-1);
    else return 1;
}

int str_to_int(string str)
{
    int n = str.size();
    int num = 0;
    for (int i=0; i<n; ++i){
        num += pow(10, n-i-1) * (int(str[i]) - int('0'));
    }
    return num;
}

int get_bit(int a, int d)
{
    d = (a / pow(10, d-1))%10;
    return d;
}

void bit_sort(int* arr, int N, int bit, int max_bit)
{
    int* arr0 = new int [N];
    int k = 0;
    int* arr1 = new int [N];
    int m = 0;
    for (int i=0; i<N; ++i){
        if (get_bit(arr[i], bit) == 0){
            arr0[k] = arr[i];
            ++k;
        }
        else{
            arr1[m] = arr[i];
            ++m;
        }
    }
    for(int i=0; i<k; ++i){
        arr[i] = arr0[i];
        cout << arr[i] << ' ';
    }
    for(int i=0; i<m; ++i){
        arr[i+k] = arr1[i];
        cout << arr[i+k] << ' ';
    }
    cout << '\n';
    delete [] arr0;
    delete [] arr1;
    if (bit < max_bit){
        bit_sort(arr, N, bit+1, max_bit);
    }
}

int main()
{
    string str;
    getline(cin, str);
    str.append(" ");
    int* arr = new int [str.size()];
    int j = 0, i = 0;
    int J = str.find(" ", j);
    int max_d = J - j;
    while (J > 0){
        arr[i] = str_to_int(str.substr(j, J-j));
        ++i;
        j = J + 1;
        J = str.find(" ", j);
        if (J - j > max_d){
            max_d = J - j;
        }
    }
    bit_sort(arr, i,  1, max_d);
    delete [] arr;
    return 0;
}
