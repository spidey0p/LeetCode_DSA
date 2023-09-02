#include <bits/stdc++.h>
using namespace std;

int ansDp(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    int n = coins.size();

    if (dp[amount][i] != -1)
        return dp[amount][n];
    if (amount == 0)
        return 1;
    if (i == n)
        return 0;
    if (amount < coins[i])
    {
        return dp[amount][i] = ansDp(i + 1, amount, coins, dp);
    }
    int take = ansDp(i, amount - coins[i], coins, dp);
    int notTake = ansDp(i + 1, amount, coins, dp);

    return dp[amount][i] = take + notTake;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(amount, vector<int>(n + 1, -1));
    return ansDp(0, amount, coins, dp);
}