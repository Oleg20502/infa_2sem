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

void replace_all(Node** head, int old_value, int new_value);

int main()
{
    Node* list = NULL;
    for (int i = 1; i <= 20; ++i) push_back(&list, i%7);
    print_list(list);
    int old, new_val;
    cin >> old >> new_val;
    replace_all(&list, old, new_val);
    print_list(list);
    return 0;
}

void replace_all(Node** head, int old_value, int new_value)
{
    Node* p_node = *head;
    while(p_node->next != NULL){
        if (p_node->value == old_value){
            p_node->value = new_value;
        }
        p_node = p_node->next;
    }
}


