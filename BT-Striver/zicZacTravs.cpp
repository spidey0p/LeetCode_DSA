#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    queue<TreeNode *> nodeQ;
    nodeQ.push(root);
    bool LtoR = true;

    while (!nodeQ.empty())
    {
        int size = nodeQ.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = nodeQ.front();
            nodeQ.pop();

            int index = (LtoR) ? i : (size - 1 - i);

            row[index] = node->val;

            if (node->left)
            {
                nodeQ.push(node->left);
            }
            if (node->right)
            {
                nodeQ.push(node->right);
            }
        }
        LtoR = !LtoR;
        res.push_back(row);
    }
    return res;
}