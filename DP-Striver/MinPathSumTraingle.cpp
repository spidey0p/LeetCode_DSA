#include <bits/stdc++.h>
using namespace std;

int minPath(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return grid[i][j];

    int down = grid[i][j] + minPath(i + 1, j, grid, dp, n);
    int diogonal = grid[i][j] + minPath(i + 1, j + 1, grid, dp, n);

    return dp[i][j] = min(down, diogonal);
}

int minPathSum(vector<vector<int>> &grid, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minPath(0, 0, grid, dp, n);
}

int main()
{
    vector<vector<int>> grid{{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};

    int n = grid.size();
    cout << minPathSum(grid, n) << endl;
}