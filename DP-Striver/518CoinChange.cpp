#include <bits/stdc++.h>
using namespace std;

// int ansDp(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
// {
//     int n = coins.size();

//     if (dp[amount][i] != -1)
//         return dp[amount][n];
//     if (amount == 0)
//         return 1;
//     if (i == n)
//         return 0;
//     if (amount < coins[i])
//     {
//         return dp[amount][i] = ansDp(i + 1, amount, coins, dp);
//     }
//     int take = ansDp(i, amount - coins[i], coins, dp);
//     int notTake = ansDp(i + 1, amount, coins, dp);

//     return dp[amount][i] = take + notTake;
// }

// int change(int amount, vector<int> &coins)
// {
//     int n = coins.size();
//     vector<vector<int>> dp(amount, vector<int>(n + 1, -1));
//     return ansDp(0, amount, coins, dp);
// }

// bool solve(string str)
// {
//     // string str = to_string(x);
//     int n = str.size();
//     for (int i = 0; i < n; i++)
//     {
//         if ((str[n - 1] == 0 && str[n - 2] == 0) || (str[n - 1] == 0 && str[n - 2] == 5) || (str[n - 1] == 5 && str[n - 2] == 7) || (str[n - 1] == 5 && str[n - 2] == 2))
//         {
//             return true;
//         }
//     }
//     return false;
// }
// int minimumOperations(string num)
// {
//     if (solve(num))
//         return 0;
//     if (num == "0")
//         return 0;
//     if (num == "10")
//         return 1;

// }

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int cnt = 0;
                for (int l = i; l <= j; ++l)
                {
                    if (nums[l] % modulo == k)
                        ++cnt;
                }
                if (cnt % modulo == k)
                    ++ans;
            }
        }
        return ans;
    }
};
// C answer