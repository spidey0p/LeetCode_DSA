#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    ;
    TreeNode *left, *right;
};
int countNodes(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
