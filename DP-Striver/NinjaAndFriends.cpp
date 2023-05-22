#include <bits/stdc++.h>
using namespace std;

int maxChoco(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;
    for (int lf = -1; lf <= 1; lf++)
    {
        for (int rg = -1; rg <= 1; rg++)
        {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + maxChoco(i + 1, j1 + lf, j2 + rg, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChoco(i + 1, j1 + lf, j2 + rg, n, m, grid, dp);

            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maxChocoCount(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return maxChoco(0, 0, m - 1, n, m, grid, dp);
}

int main()
{
    vector<vector<int>> grid{{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};

    int n = grid.size();
    int m = grid[0].size();

    cout << "Max number of chocolet collected by these people is: ";
    cout << maxChocoCount(n, m, grid);
}