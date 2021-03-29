#include <random>
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <fstream>

int pow(int a, int p)
{
    if (p > 0) return a*pow(a, p-1);
    else return 1;
}

void write(std::string a, std::string path)
{
    std::ofstream out;
    out.open(path);
    if (out.is_open(), std::ios::app)
        out << a << std::endl;
    out.close();
}

void clear(std::string path)
{
    std::ofstream out;
    out.open(path);
    out.close();
}

void print_array(int* arr, int N, int row = 22)
{
    for (int k=0; k < (N-1)/row+1; ++k){
        for (int i=0; i<row; ++i){
            if (i+k*row < N) std::cout << arr[i+k*row] << ' ';
        }
        std::cout << '\n';
    }
}

int* create_random_array(int N, int lower_bound = 0, int upper_bound=10)
{
    auto t = std::chrono::high_resolution_clock::now();
    std::mt19937 engine(time(0));
    std::uniform_int_distribution<int> int_dist(lower_bound, upper_bound);

    int* arr = new int [N];
    for (int i=0; i<N; ++i){
        arr[i] = int_dist(engine);
    }
    return arr;
}

int time_count(void (*f)(int* , int), int N, int b, int val=1000)
{
    int* arr = create_random_array(N, 0, b);
    auto start = std::chrono::high_resolution_clock::now();
    f(arr, N);
    auto end = std::chrono::high_resolution_clock::now();
    auto nsec = end - start;
    int time = nsec.count()/val;
    //std::cout << time << " mksec" << std::endl;
    //print_array(arr, N);
    delete [] arr;
    return time;
}

void bubble_sort(int* arr, int N)
{
    int a;
    for (int i=N-1; i>=0; --i){
        for (int j=0; j<i; ++j){
            if (arr[j] > arr[j+1]){
                a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }
        }
    }
}

void selection_sort(int* arr, int N)
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
        }
        min = 2147483647;
    }
}

void insertion_sort(int* arr, int N)
{
    int a;
    for (int i=1; i<N; ++i){
        for (int j=i; j>0 ;--j){
            if (arr[j] < arr[j-1]){
                a = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = a;
            }
        }
    }
}

void quick_sort(int* arr, int N)
{
    int a;
    int p = arr[N/2];
    int s = 0;
    int f = N-1;
    while (s <= f){
        while (arr[s] < p) ++s;
        while (arr[f] > p) --f;
        if (s <= f){
            a = arr[f];
            arr[f] = arr[s];
            arr[s] = a;
            ++s;
            --f;
        }
    }
    if (f > 0) quick_sort(arr, f+1);
    if (N - 1 > s) quick_sort(arr+s, N-s);
}

void qsort(int* arr, int b, int e)
{
    int l = b, r = e;
    int piv = arr[(l + r) / 2];
    while (l <= r){
        while (arr[l] < piv)
            l++;
        while (arr[r] > piv)
            r--;
        if (l <= r){
            std::swap(arr[l++], arr[r--]);
        }
    }
    if (b < r)
        qsort(arr, b, r);
    if (e > l)
        qsort(arr, l, e);
}

void qsort(int* arr, int N)
{
    qsort(arr, 0, N);
}

void test(void (*f)(int* , int), int e, int n0, int nf, int step, int bound)
{
    std::string path = "C:/Олег/Github/infa_2sem/Lab8/Sorting_data.txt";
    int time = 2147483647;
    int t;
    std::string text = "";
    for (int n=n0; n<=nf+1; n *= step){
        for (int i=0; i<e; ++i){
            t = time_count(f, n, bound);
            if (t < time)
                time = t;
        }
        text += std::to_string(n) + "; ";
        text += std::to_string(time) + " мкс;\n";
        std::cout << n << ' ' << time << " mksec" << '\n';
        time = 2147483647;
    }
    text += "\n";
    write(text, path);
}

int main()
{
    int N = 10000;
    int bound = 10000;

    //test(bubble_sort, 5, 10000, 40000, 10000, 10000);
    //test(qsort, 5, 10000, 40000, 10000, 10000);
    test(quick_sort, 1, pow(2, 30), pow(2, 30), 2, 100000000);
    return 0;
}

