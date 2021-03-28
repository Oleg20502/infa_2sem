#include <iostream>
#include <string>

using namespace std;

struct Slipper{
  int size;
  int step;
  int distance = 0;
  Slipper* next;
};

Slipper* find_val(Slipper* head, int a)
{
    Slipper* p_node = head;
    Slipper* p = NULL;
    while (p_node != NULL){
        if (p_node->size == a){
            p = p_node;
        }
        p_node = p_node->next;
    }
    return p;
}

void push_back(Slipper** head, int value, int I)
{
    if (*head == NULL) {
        *head = new Slipper;
        (*head)->size = value;
        (*head)->step = I;
        (*head)->next = NULL;
        return;
    }
    Slipper* p_node = *head;
    while (p_node->next != NULL) {
        p_node = p_node->next;
    }
    Slipper* new_node = new Slipper;
    p_node->next = new_node;
    new_node->size = value;
    new_node->step = I;
    new_node->next = NULL;
}

int main()
{
    int N;
    cin >> N;
    Slipper* first = NULL;
    int s;
    Slipper* p;
    for (int i=0; i<N; ++i){
        cin >> s;
        if (s > 0){
            p = find_val(first, -s);
            if (p != NULL){
                p->distance = i - p->step;
            }
        }
        else{
            p = find_val(first, s);
            if ((p != NULL) && (p->distance == 0)){
                p->step = i;
            }
            else{
                push_back(&first, s, i);
            }
        }
    }
    Slipper* p_node = first;
    int dis = 2147483647;
    while (p_node != NULL){
        if ((p_node->distance < dis) && (p_node->distance > 0)){
            dis = p_node->distance;
        }
        p_node = p_node->next;
    }
    if (dis < 2147483647){
        cout << dis << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
