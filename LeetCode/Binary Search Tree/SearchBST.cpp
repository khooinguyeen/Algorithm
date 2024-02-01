/*

700. Search in a Binary Search Tree
Easy

You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null.

*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return (NULL);
        if (root->val == val)
            return (root);
        if (val < root->val)
            return (searchBST(root->left, val));
        else
            return (searchBST(root->right, val));
    }
};

int main()
{
    TreeNode *myBST = new TreeNode(4,
        new TreeNode(2,
            new TreeNode(1),
            new TreeNode(3)),
        new TreeNode(7));
    
    Solution solution;
    TreeNode *res = solution.searchBST(myBST, 7);
    cout << res->val << endl;
    delete myBST;
    return (0);
    
}