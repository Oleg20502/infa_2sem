#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int T;

typedef struct Stack *Link_Stack;

inline void ERR(const char* s)
{
    fputs(s, stderr);
    exit(1);
}

struct Stack{
    int NumEl, Size;
    T Items[];
};

Link_Stack Stack_ini(int N)
{
    Link_Stack a = (Link_Stack)malloc(sizeof(struct Stack) + N*sizeof(T));
    a->NumEl = 0;
    a->Size = N;
    return a;
}

Link_Stack Stack_free(Link_Stack a)
{
    free(a);
    return NULL;
}

int Stack_Is_Empty(Link_Stack a)
{
    return a->NumEl==0;
}

int Stack_ Is_Full(Link_Stack a)
{
    return a->NumEl==a->Size;
}

void Stack_push(Link_Stack a, T New_el)
{
    if(Stack_Is_Full(a))
        ERR("Stack::push: stack is full");
    a->Items[a->NumEl++] = New_el;
}

T Stack_pop(Link_Stack a)
{
    if(Stack_Is_Empty(a))
        ERR("Stack::pop: stack is empty");
    return a->Items[--a->NumEl];
}*/

struct Node {
    int value;
    Node* next;
};

void push_left(Node** head, int value)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }
    Node* cell = new Node;
    cell->value = value;
    cell->next = *head;
    (*head) = cell;
}

int pop(Node** head)
{
    int val;
    Node* p_node = *head;
    val = p_node->value;
    (*head) = p_node->next;
    delete p_node;
    return val;
}

void delete_list(Node** head)
{
    if (*head != NULL){
        Node* p_node = *head;
        Node* pop_node;
        while (p_node->next != NULL){
            pop_node = p_node;
            p_node = p_node->next;
            delete pop_node;
        }
    }
}

int main()
{
    Node* list = NULL;
    int a = 1;
    int size = 0, val;
    cin >> a;
    while (a != 0){
        if (a > 0){
            push_left(&list, a);
            ++size;
        }
        else if (size!=0){
            if(abs(a) < list->value){
                list->value += a;
            }
            else {
                pop(&list);
                --size;
            }
        }
    cin >> a;
    }
    if (size == 0){
        val = -1;
    }
    else val = list->value;
    cout << size << " " << val;
    delete_list(&list);
    return 0;
}


