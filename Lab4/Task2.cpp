#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int value;
    Node* next;
};

void clear_list(Node** head);
void push_back(Node** head, int value);

void print_list(Node* head)
{
    Node* p_node = head;
     while(p_node != NULL){
        cout << p_node->value<<' ';
        p_node = p_node->next;
    }
    cout<<endl;
}

int main()
{
    Node* list = NULL;
    for (int i = 1; i <= 10; ++i) push_back(&list, i);
    print_list(list);
    clear_list(&list);
    return 0;
}

void clear_list(Node** head)
{
    if (*head != NULL){
        Node* new_head = (*head)->next;
        delete *head;
        *head  = new_head;
    }
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
