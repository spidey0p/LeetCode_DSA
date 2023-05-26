#include <bits/stdc++.h>
using namespace std;

int subSet(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
        return dp[ind][target] = target;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTake = subSet(ind - 1, target, arr, dp);

    int take = 0;
    if (arr[ind] <= target)
    {
        take = subSet(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = notTake + take;
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subSet(n - 1, k, arr, dp);
}
int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    cout << "The number of subset found are:" << findWays(arr, k) << endl;
}