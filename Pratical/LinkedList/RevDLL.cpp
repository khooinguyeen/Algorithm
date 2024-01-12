/*
EASY

Given a Doubly Linked List, the task is to reverse the given Doubly Linked List.
*/

#include <iostream>
using namespace std;

class Node
{
    private:
        int data;
        Node *next;
        Node *prev;
    public:

        Node(int x) : data(x), next(nullptr), prev(nullptr) {}

        void push(Node **head, int x)
        {
            Node *newNode = new Node(x);
            newNode->prev = NULL;
            newNode->next = *head;
            if ((*head) != NULL)
                (*head)->prev = newNode;
            *head = newNode;
        }
        void print(Node *node)
        {
            while (node != nullptr)
            {
                cout << node->data << " ";
                node = node->next;
            }
            cout << endl;
        }

        Node* reverseDLL(Node *head)
        {
            if (head == NULL || head->next == NULL)
                return head;

            Node *temp = NULL;
            while (head != nullptr)
            {
                temp = head->prev;
                head->prev = head->next;
                head->next = temp;
                head = head->prev;
            }
            return temp->prev;
        }
};

int main()
{
    Node *myNode = NULL;
    myNode->push(&myNode, 2);
    myNode->push(&myNode, 42);
    myNode->push(&myNode, 32);
    myNode->print(myNode);
    Node *newNode = myNode->reverseDLL(myNode);
    newNode->print(newNode);
    return (0);
}