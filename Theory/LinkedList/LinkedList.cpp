#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node* next;
};

void insert(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

Node *item_ahead(Node *head, Node *x)
{
    if ((head == NULL) || (head->next == NULL))
        return (NULL);
    if (head->next == x)
        return (head);
    else
        return (item_ahead(head->next, x));
}

void remove(Node **head, Node **x)
{
    Node *p; // Item pointer
    Node *pred; // predecessor pointer

    p = *head;
    pred = item_ahead(*head, *x);
    if (pred == NULL)
        *head = p->next;
    else
        pred->next = (*x)->next;
    delete *x;    
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
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 0);
    display(&head);

    cout << endl;

    Node* res = search(head, 3);
    cout << "search result: " << res << " " << res->data << endl;
    cout << "after remove the node containing data 3 \n";
    remove(&head, &res);
    display(&head);
    return 0;
}