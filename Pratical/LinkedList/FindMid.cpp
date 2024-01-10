/* 
EASY

Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
    private:
        int value;
        Node *next;
    public:
        Node() : value(0), next(nullptr) {}
        Node(int x) : value(x), next(nullptr) {}
        Node(int x, Node *next) : value(x), next(next) {}

        // Solution
        int getMiddle(Node *head)
        {
            vector<int> v;
            while (head != nullptr)
            {
                cout << head->value << " ";
                v.push_back(head->value);
                head = head->next;
            }
            cout << endl;
            return (v[v.size()/2]);
        }
};

int main()
{
    Node mynode(1, new Node(2, new Node(3, new Node(9, new Node(42, new Node(22))))));
    cout << mynode.getMiddle(&mynode) << endl;
    return (0);
}