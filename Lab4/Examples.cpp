#include <iostream>


using std::cout;
using std::cin;
using std::endl;

struct Node{
    int value;
    Node* next;
};

typedef struct Node{
    int value;
    struct Node * next;
} Node;

void push_back(Node** head, int value)
{
    if (*head == NULL){
        *head = new Node;
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }
    Node* p_node = head;
    while(p_node->next != NULL){
        p_node = p_node->next;
    }
    Node * new_node = new Node;
    new_node->value = value;
    new_node->next = NULL;
}

void print_list(Node* head)
{
    Node* P_node = head;
     while(p_node != NULL){
        cout << p_niode->value<<' ';
        p_node = p_node->next;
    }
    cout<<endl;
}

Node* init_list(int first_value)
{
    Node* head = new Node;
    head->value = first_value;
    head->next = NULL
    return head;
}

struct List{
    Nide* head;
    int size;
    Node* last;
};

int main()
{
    Node* list = NULL;
    Node* list = init_list(1);
    for (int i=1; i<=10; ++i) push_back(&list, i);
    print_list(list);
    return 0;
}
