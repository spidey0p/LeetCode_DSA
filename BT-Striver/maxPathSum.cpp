#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};
int findMaxPathSum(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int lp = max(0, findMaxPathSum(root->left, maxi));
    int rp = max(0, findMaxPathSum(root->right, maxi));
    int data = root->val;
    maxi = max(maxi, (lp + rp) + data);
    return max(lp, rp) + data;
}
int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;

    findMaxPathSum(root, maxi);
    return maxi;
}