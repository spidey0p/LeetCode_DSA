#include <bits/stdc++.h>
using namespace std;

bool subSet(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;

    if (ind == 0)
        return dp[ind][target] = target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTake = subSet(ind - 1, target, arr, dp);
    bool take = false;

    if (arr[ind] <= target)
    {
        take = subSet(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = notTake || take;
}

int minSubSetDiff(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subSet(n - 1, i, arr, dp);
    }

    int max = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            max = min(max, diff);
        }
    }
    return max;
}
int main()
{

    vector<int> arr = {1, 2, 3, 4};

    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubSetDiff(arr, n);
}

/*The minimum absolute difference is: 0*/