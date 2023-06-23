#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> nodes;
        postOrder(root, nodes);
        return nodes;
    }

private:
    void postOrder(TreeNode *root, vector<int> &nodes)
    {
        if (!root)
        {
            return;
        }

        postOrder(root->left, nodes);
        postOrder(root->right, nodes);
        nodes.push_back(root->val);
    }
};