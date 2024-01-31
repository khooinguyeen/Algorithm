/*

199. Binary Tree Right Side View
Medium

Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

*/

#include <iostream>
#include <vector>
#include <queue>

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

class Solution
{
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            vector<int> result;
            if (!root)
                return (result);
            queue<TreeNode*> levelQueue;
            levelQueue.push(root);

            while (!levelQueue.empty())
            {
                int size = levelQueue.size();
                for (int i = 1; i <= size; i++)
                {
                    TreeNode *currentNode = levelQueue.front();
                    levelQueue.pop();
                    if (i == size)
                        result.push_back(currentNode->val);
                    if (currentNode->left)
                        levelQueue.push(currentNode->left);
                    if (currentNode->right)
                        levelQueue.push(currentNode->right);
                }
            }
            return (result);
        }
};

class RecursiveSolution
{
    public:
        void recursion(TreeNode *curr, size_t level, vector<int> &res) {
            if(curr == NULL)
                return;

            if(res.size() == level)
                res.push_back(curr->val);
            
            recursion(curr->right, level+1, res);
            recursion(curr->left, level+1, res);    
        }

        vector<int> rightSideView(TreeNode* root) {
            vector<int> res;
            TreeNode *curr = root;

            recursion(curr, 0, res);
            return res;
        }
};

int main()
{
    TreeNode *root = new TreeNode(1, 
        new TreeNode(2, 
            nullptr, 
            new TreeNode(5, 
                new TreeNode(4), 
                nullptr)),
        new TreeNode(3, 
            new TreeNode(6),
            nullptr));
    RecursiveSolution solution;
    vector <int> rightView = solution.rightSideView(root);
    for (int i : rightView) 
        cout << i << " ";
    cout << endl;
    delete root;
    return (0);
}