#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int jump_k_steps(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int minStapes = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (ind - i >= 0)
        {
            int jump = jump_k_steps(ind - i, height, dp, k) + abs(height[ind] - height[ind - i]);
            minStapes = min(jump, minStapes);
        }
    }
    return dp[ind] = minStapes;
}

int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);
    return jump_k_steps(n - 1, height, dp, k);
}
int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k;
    cout << "Enter the size of steps:";
    cin >> k;
    vector<int> dp(n, -1);
    cout << solve(n, height, k);
}