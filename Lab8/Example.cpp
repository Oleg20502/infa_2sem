#include <random>
#include <iostream>

int main()
{
    std::mt19937 engine(11);
    std::uniform_int_distribution<int> int_dist(0, 1);
    for (int i=0; i<10; ++i){
        std::cout << int_dist(engine) << '\n';
    }
    //int a = int_dist(engine);

    return 0;
}
