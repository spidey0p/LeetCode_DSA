// Recursion Approach
// method 1

/*#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int left = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    }
    return dp[ind] = min(right, left);
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    cout << solve(n - 1, height, dp);
}*/

// Tabulation approach
// method 2

/*#include <bits/stdc++.h>
using namespace std;

void FrogJump(int i, vector<int> &heights, vector<int> &dp)
{
    int n = heights.size();
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int JumpOne = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int JumpTwo = INT_MAX;
        if (i > 1)
        {
            JumpTwo = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(JumpOne, JumpTwo);
    }
    cout << dp[n - 1];
}

int main()
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int n = heights.size();
    vector<int> dp(n, -1);
    FrogJump(n - 1, heights, dp);
    return 0;
}*/

// Space optimization
// method 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int jumpTwo = INT_MAX;
        int JumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
        {
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);
        }
        int curr_i = min(JumpOne, jumpTwo);
        prev2 = prev;
        prev = curr_i;
    }
    cout << prev;
}