#include <bits/stdc++.h>
using namespace std;

int mod = (int)1e9 + 7;

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();

    vector<vector<int>> dp(n, (vector<int>(target + 1, 0)));

    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (nums[0] != 0 && nums[0] <= target)
        dp[0][nums[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            int notTake = dp[ind - 1][tar];

            int take = 0;
            if (nums[ind] <= tar)
                take = dp[ind - 1][tar - nums[ind]];

            dp[ind][tar] = (notTake + take) % mod;
        }
    }
    return dp[n - 1][target];
}
int targetSum(int n, int target, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2)
        return 0;

    return findTargetSumWays(arr, (totSum - target) / 2);
}