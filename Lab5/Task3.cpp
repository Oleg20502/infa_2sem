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
    if (*head == NULL){
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

void push_middle(Node** head, int size, int value)
{
    Node* p_node = *head;
    if (size == 0 or size == 1){
        push_left(head, value);
    }
    else{
        for (int i=0; i < size/2-1; ++i){
            p_node = p_node->next;
        }
        Node* add_node = p_node->next;
        push_left(&add_node, value);
        p_node->next = add_node;
    }
}

int pop_last(Node** head)
{
    int val;
    Node* p_node = *head;
    if (p_node != NULL){
        if (p_node->next == NULL){
            val = p_node->value;
            delete p_node;
            (*head) = NULL;
            return val;
        }
        while ((p_node->next)->next != NULL){
            p_node = p_node->next;
        }
        val = (p_node->next)->value;
        delete p_node->next;
        p_node->next = NULL;
        return val;
    }
    else return -2147483648;
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
    Node* queue = NULL;
    int size = 0;
    int N;
    cin >> N;
    char s;
    int val;
    for (int i=0; i<N; ++i){
        cin >> s;
        if (s == '+'){
            cin >> val;
            ++size;
            push_left(&queue, val);
        }
        else if(s == '*'){
            cin >> val;
            push_middle(&queue, size, val);
            ++size;
        }
        else if(s == '-'){
            --size;
            cout << pop_last(&queue) << endl;
        }
    }
    delete_list(&queue);
    return 0;
}
