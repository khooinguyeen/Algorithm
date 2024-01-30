/*

104. Maximum Depth of Binary Tree
Easy

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return (0);
        int l = 0, r = 0;
        if (root->left != nullptr)
            l = 1 + maxDepth(root->left);
        else
            l += 1;
        if (root->right != nullptr)
            r = 1 + maxDepth(root->right);
        else
            r += 1;
        return max(l, r);
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return (0);
        return (max(maxDepth(root->left), maxDepth(root->right)) + 1);
            
    }
};

int main()
{
    TreeNode* root = new TreeNode(4,
        new TreeNode(2,
            new TreeNode(1),
            new TreeNode(3)
        ),
        new TreeNode(6,
            new TreeNode(5),
            new TreeNode(7,
                new TreeNode(8),
                nullptr)
        )
    );

    Solution solution;
    cout << solution.maxDepth(root) << endl;
    Solution2 solution2;
    cout << solution2.maxDepth(root) << endl;
    delete root;
    return (0);
}