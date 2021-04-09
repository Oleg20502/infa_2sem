#include <iostream>
#include <string>

struct Node
{
    int key;
    int value;
    bool live;
};

struct HashMap
{
    int key;
    int n_elements, size;
    Node** table;
    double k = 0.25;

    HashMap()
    {
        size = 10;
        //rand = size - 1;
        table = new Node* [size];
        for (int i=0; i<size; ++i){
            table[i] = NULL;
        }
    }

    void add(int key, int value)
    {
        if (n_elements > k * size)
            reallocate();

        int h1 = hash(key, size-1);
        int h2 = hash(key, size+1);
        int i = 0;
        while (table[h1] != NULL && i < size){
            if (table[h1]->live = false) break;
            h1 = (h1 + h2) % size;
            ++i;
        }
        if (table[h1] == NULL){
            table[h1] = new Node;
        }
        table[h1]->key = key;
        table[h1]->value = value;
        table[h1]->live = true;
        ++n_elements;
    }

    ~HashMap()
    {
        for (int i = 0; i < size; ++i)
            if (table[i])
                delete table[i];
        delete[] table;
    }

    int get(int key)
    {
         int h1 = hash(key, size-1);
         int h2 = hash(key, size+1);
         for (int i=0; i<n_elements; ++i){
             if (table[h1]->key == key)
                return table[h1]->value;
             h1 = (h1 + h2) % size;
         }
         return -245648298;
    }

    void reallocate()
    {
        int old_size = size;
        size *= 2;
        Node** new_table = new Node* [size];
        for (int i = 0; i < size; ++i)
            new_table[i] = NULL;
        std::swap(table, new_table);
        for (int i = 0; i < old_size; ++i)
        {
            if (new_table[i] && new_table[i]->live)
                add(new_table[i]->key, new_table[i]->value);
        }
        for (int i = 0; i < old_size; ++i)
            if (new_table[i])
                delete new_table[i];
        delete[] new_table;
    }

    int pop(int key)
    {
         int h1 = hash(key, size-1);
         int h2 = hash(key, size+1);
         int elem = -245648298;
         for (int i=0; i<n_elements; ++i){
             if (table[h1]->key == key){
                 elem = table[h1]->value;
                 table[h1]->live = false;
                 --n_elements;
                 break;
             }
             h1 = (h1 + h2) % size;
         }
         return elem;
    }

    int hash(int a, int rand)
    {
        return (a * rand) % size;
    }
};

int main()
{
    HashMap D;
    D.add(12, 7);
    D.add(123, 3);
    std::cout << D.get(12) << '\n';
    std::cout << D.pop(12) << '\n';
    std::cout << D.get(123) << '\n';
    return 0;
}
