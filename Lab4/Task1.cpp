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

void push_left(Node** head, int value);
void push_back(Node ** head, int value);

int main()
{
    Node* list = NULL;
    //for (int i = 1; i <= 10; ++i) push_back(&list, i);
    int v;
    cin>>v;
    push_left(&list, v);
    print_list(list);
    return 0;
}

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

void push_back(Node** head, int value)
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
