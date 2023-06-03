#include <bits/stdc++.h>
using namespace std;

int maxSum(int ind, vector<int> &arr, vector<int> &dp)
{
    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    int pick = arr[ind] + maxSum(ind - 2, arr, dp);
    int notPick = 0 + maxSum(ind - 1, arr, dp);

    return dp[ind] = max(pick, notPick);
}

int maxSumPath(int n, vector<int> &arr)
{
    vector<int>(n, -1);
    return maxSum(n - 1, arr, arr);
}
int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();

    cout << maxSumPath(n, arr) << endl;
}
