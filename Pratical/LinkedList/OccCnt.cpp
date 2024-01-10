/*
EASY

Given a singly linked list and a key, count the number of occurrences of given key in the linked list.
*/

#include <iostream>
using namespace std;

class Node
{
    private:
        int data;
        Node *next;
    public:
        Node() : data(0), next(nullptr) {}
        Node(int x) : data(x), next(nullptr) {}
        Node(int x, Node *next) : data(x), next(next) {}

        int count(Node* head, int search_for)
        {
            int cnt = 0;

            while (head != nullptr)
            {
                if (head->data == search_for)
                    cnt++;
                head = head->next;
            }
            return (cnt);
        }
};

int main()
{
    Node mynode(1, new Node(2, new Node(3, new Node(9, new Node(2, new Node(42))))));
    cout << mynode.count(&mynode, 2) << endl;
    return (0);
}