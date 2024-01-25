/*

2095. Delete the Middle Node of a Linked List
Medium

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:

        /*
        1. Traverse through the list and count the total node (n)
        2. Find the n/2 node
        3. Remove that node and let the *next of the prev node = next node
        */

        int countNode(ListNode *head)
        {
            int counter = 0;
            ListNode *current = head;
            while (current != nullptr)
            {
                counter++;
                current = current->next;
            }
            return (counter);
        }

        void removeNode(ListNode *node)
        {
            if (node == nullptr)
                return;
            if (node->next == nullptr)
            {

            }
            ListNode *nextNode = node->next;
            node->val = nextNode->val;
            node->next = nextNode->next;
            delete nextNode;
        }

        ListNode *deleteMiddle(ListNode *head) 
        {
            int mid = countNode(head)/2;
            int count = 0;
            ListNode *current = head;
            if (countNode(head) == 2)
            {
                current->next = nullptr;
                return (head);
            }
            if (mid == 0)
            {
                delete head;
                return head;
            }
            while (current != nullptr)
            {
                if (count == mid)
                {
                    removeNode(current);
                }
                current = current->next;
                count++;
            }
            return (head);
        }

        void display(ListNode *head)
        {
            ListNode *current = head;
            while (current != nullptr)
            {
                cout << current->val << " ";
                current = current->next;
            }
            cout << endl;
        }
};

class Solution2 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL )
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = slow;

        while(fast != NULL && fast -> next != NULL)  {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = slow -> next;

        return head;
    }
};

int main()
{
    Solution solution;
    //ListNode *LinkedList = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(7, new ListNode(1, new ListNode(2, new ListNode(6)))))));
    ListNode *myList = new ListNode(3, new ListNode(1, new ListNode(2)));
    cout << solution.countNode(myList);
    cout << endl;
    solution.display(myList);
    solution.deleteMiddle(myList);
    solution.display(myList);
    return (0);
}