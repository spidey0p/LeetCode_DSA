
#include <bits/stdc++.h>

using namespace std;

int getMaxUtil(int i, int j, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    // Base Conditions
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return grid[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + getMaxUtil(i - 1, j, m, grid, dp);
    int leftDiagonal = grid[i][j] + getMaxUtil(i - 1, j - 1, m, grid, dp);
    int rightDiagonal = grid[i][j] + getMaxUtil(i - 1, j + 1, m, grid, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        int ans = getMaxUtil(n - 1, j, m, grid, dp);
        maxi = max(maxi, ans);
    }

    return maxi;
}

int main()
{

    vector<vector<int>> grid{{1, 2, 10, 4},
                             {100, 3, 2, 1},
                             {1, 1, 20, 2},
                             {1, 2, 2, 1}};

    cout << getMaxPathSum(grid);
}