#include <bits/stdc++.h>
using namespace std;

class Node 
{
    public:
        int data;
        Node* next;
};

void push(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void display(Node** head) 
{
    Node* current = *head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

Node *search(Node* head, int x)
{
    if (head == NULL) { 
        return NULL;
    }
    if (head->data == x) {
        return head;
    } else {
        return search(head->next, x);
    }
}

int main()
{
    Node* head = NULL;
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 0);
    display(&head);

    cout << endl;

    Node* res = search(head, 3);
    cout << "search result: " << res << " " << res->data << endl;

    return 0;
}