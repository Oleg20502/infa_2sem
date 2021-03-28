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

void sort(int* arr, int N)
{
    int min = 2147483647;
    int i_min, c;
    for (int i=0; i < N; ++i){
        for (int j=i; j<N; ++j){
            if (arr[j] < min){
                min = arr[j];
                i_min = j;
            }
        }
        if (min < 2147483647){
            c = arr[i];
            arr[i] = min;
            arr[i_min] = c;
            i_min = i;
        }
        min = 2147483647;
    }
}

int main()
{
    string str;
    getline(cin, str);
    str.append(" ");
    int* arr1 = new int [str.size()];
    int* arr2 = new int [str.size()];
    int j = 0, unev_num = 0, ev_num=0;
    int a;
    int J = str.find(" ", j);
    while (J > 0){
        a = str_to_int(str.substr(j, J-j));
        if (a%2 == 0){
            arr1[ev_num] = a;
            ++ev_num;
        }
        else{
            arr2[unev_num] = a;
            ++unev_num;
        }
        j = J + 1;
        J = str.find(" ", j);
    }
    sort(arr1, ev_num);
    sort(arr2, unev_num);
    for (int i=0; i<ev_num; ++i){
        cout << arr1[i] << ' ';
    }
    for (int i=0; i<unev_num; ++i){
        cout << arr2[i] << ' ';
    }
    delete [] arr1;
    delete [] arr2;
    return 0;
}
