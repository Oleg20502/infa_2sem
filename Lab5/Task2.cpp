#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

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

int main(){
    std::string s;
    int b;
    Node* num_list = NULL;
    while (cin >> s){
        if (s == "+"){
            b = pop(&num_list);
            num_list->value += b;
        }
        else if (s == "-"){
            b = pop(&num_list);
            num_list->value -= b;
        }
        else if (s == "*"){
            b = pop(&num_list);
            num_list->value *= b;
        }
        else if (s == "/"){
            b = pop(&num_list);
            num_list->value /= b;
        }
        else {
            push_left(&num_list, stoi(s));
        }
    }
    cout << num_list->value;
    delete_list(&num_list);
    return 0;
}
