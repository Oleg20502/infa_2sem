#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int value;
    Node* next;
};

void print_list(Node* head)
{
    Node* p_node = head;
    while(p_node != NULL){
        cout << p_node->value<<' ';
        p_node = p_node->next;
    }
    cout<<endl;
}

void push_back(Node ** head, int value)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }
    Node * p_node = *head;
    while (p_node->next != NULL) {
        p_node = p_node->next;
    }
    Node * new_node = new Node;
    p_node->next = new_node;
    new_node->value = value;
    new_node->next = NULL;
}

int pop(Node** head, int index);

int main()
{
    Node* list = NULL;
    for (int i = 1; i <= 1; ++i) push_back(&list, i);
    print_list(list);
    int p;
    cin >> p;
    cout << pop(&list, p) << endl;
    print_list(list);
    return 0;
}

int pop(Node** head, int index)
{
    int val;
    int i = 0;
    Node * p_node = *head;
    if (index == 0){
        *head = p_node->next;
        val = p_node->value;
        delete p_node;
        return val;
    }
    else{
        while (p_node->next != NULL and i < index-1) {
            p_node = p_node->next;
            ++i;
        }
        if (i == index-1){
            Node* pop_node = p_node->next;
            val = pop_node->value;
            p_node->next = (pop_node)->next;
            delete pop_node;
            return val;
        }
        else{
            return INT_MIN;
        }
    }
}
