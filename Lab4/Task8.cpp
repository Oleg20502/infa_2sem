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

void push_back(Node** head, int value)
{
    if (*head == NULL) {
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }
    Node* p_node = *head;
    while (p_node->next != NULL) {
        p_node = p_node->next;
    }
    Node* new_node = new Node;
    p_node->next = new_node;
    new_node->value = value;
    new_node->next = NULL;
}

int unique(Node* head);
void reverse(Node** head);

int main()
{
    Node* list = NULL;
    for (int i = 1; i <= 20; ++i) push_back(&list, i);
    print_list(list);
    reverse(&list);
    print_list(list);
    return 0;
}

void reverse(Node** head)
{
    Node* pre_node = *head;
    Node* p_node = pre_node->next;
    Node* past_node = p_node->next;
    pre_node->next = NULL;
    while (past_node->next != NULL) {
        p_node->next = pre_node;
        pre_node = p_node;
        p_node = past_node;
        past_node = past_node->next;
    }
    p_node->next = pre_node;
    past_node->next = p_node;
    *head = past_node;
}
