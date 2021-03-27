#include <iostream>
#include <string>

using namespace std;

struct Citizen{
    string name;
    int type;
    Citizen* next;
    Citizen* previous;
};

void delete_list(Citizen** head)
{
    if (*head != NULL){
        Citizen* p_node = *head;
        Citizen* pop_node;
        while (p_node->next != *head){
            pop_node = p_node;
            p_node = p_node->next;
            delete pop_node;
        }
    }
}

void print_list(Citizen* head)
{
    Citizen* p_node = head;
    cout << p_node->name << ' ' << p_node->type << endl;
    p_node = p_node->next;
    while(p_node != head){
        cout << p_node->name << ' ' << p_node->type << endl;
        p_node = p_node->next;
    }
}

int main()
{
    int n;
    cin >> n;
    int news;
    cin >> news;
    int size = n;
    Citizen* start = new Citizen;
    cin >> (start->name) >> (start->type);
    start->previous = start;
    Citizen* p_node = start;
    for (int i = 1; i<n; ++i){
        Citizen* s = new Citizen;
        cin >> (s->name) >> (s->type);
        p_node->next = s;
        s->previous = p_node;
        s->next = start;
        start->previous = s;
        p_node = p_node->next;
    }
    int m;
    cin >> m;
    Citizen* link = start;
    for (int i = 0; i<m; ++i){
        if (size > 1){
            int t = link->type;
            if(t == 0){
                news = 1 - news;
            }
            if((t == 0) && (news == 1)){
                link->type = true;
            }
            else if((t == 1) && (news == 0)){
                (link->previous)->next = link->next;
                (link->next)->previous = link->previous;
                if (link == start){
                    start = link->next;
                }
                --size;
            }
            link = link->next;
        }
    }
    print_list(start);
    delete_list(&start);
    return 0;
}
