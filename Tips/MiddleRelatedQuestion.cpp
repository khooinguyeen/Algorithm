/*

When working with question that require handling with the middle element of a data structure, we can use 2 pointer.
One fast and one slow iterator.
The fast one move 2 steps per turn
The slow one move 1 step per turn

=> WHen the fast one reach the end, the slow one reach the middle

EXAMPLE: 

2095. Delete the Middle Node of a Linked List
Solved
Medium

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/

// Definition for singly-linked list.

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