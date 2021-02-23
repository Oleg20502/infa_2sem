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

void remove(Node ** head, int value);

int main()
{
    Node* list = NULL;
    for (int i = 1; i <= 10; ++i) push_back(&list, i);
    print_list(list);
    int p;
    cin >> p;
    remove(&list, p);
    print_list(list);
    return 0;
}

void remove(Node** head, int value)
{
    Node* p_node = *head;
    if (p_node->value == value){
        *head = p_node->next;
        delete p_node;
    }
    else{
        while(p_node->next != NULL and (p_node->next)->value != value) {
            p_node = p_node->next;
        }
        Node* pop_node = p_node->next;
        p_node->next = (pop_node)->next;
        delete pop_node;
    }
}
