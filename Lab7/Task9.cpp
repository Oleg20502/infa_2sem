#include <iostream>
#include <string>

using namespace std;

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
    int j = 0;
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
    return 0;
}
