
// #include <bits/stdc++.h>

// using namespace std;

// int getMaxUtil(int i, int j, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
// {

//     // Base Conditions
//     if (j < 0 || j >= m)
//         return -1e9;
//     if (i == 0)
//         return grid[0][j];

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int up = grid[i][j] + getMaxUtil(i - 1, j, m, grid, dp);
//     int leftDiagonal = grid[i][j] + getMaxUtil(i - 1, j - 1, m, grid, dp);
//     int rightDiagonal = grid[i][j] + getMaxUtil(i - 1, j + 1, m, grid, dp);

//     return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
// }

// int getMaxPathSum(vector<vector<int>> &grid)
// {

//     int n = grid.size();
//     int m = grid[0].size();

//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     int maxi = INT_MIN;

//     for (int j = 0; j < m; j++)
//     {
//         int ans = getMaxUtil(n - 1, j, m, grid, dp);
//         maxi = max(maxi, ans);
//     }

//     return maxi;
// }

// int main()
// {

//     vector<vector<int>> grid{{1, 2, 10, 4},
//                              {100, 3, 2, 1},
//                              {1, 1, 20, 2},
//                              {1, 2, 2, 1}};

//     cout << getMaxPathSum(grid);
// }

// For minimum path
// #include <bits/stdc++.h>
// using namespace std;

// int pathSum(vector<vector<int>> &grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, 0));

//     for (int j = 0; j < m; j++)
//     {
//         dp[0][j] = grid[0][j];
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int up = grid[i][j] + dp[i - 1][j];

//             int leftDig = grid[i][j];
//             if (j - 1 >= 0)
//                 leftDig += dp[i - 1][j - 1];
//             else
//                 leftDig += 1e9;

//             int rightDig = grid[i][j];
//             if (j + 1 < m)
//                 rightDig += dp[i - 1][j + 1];
//             else
//                 rightDig += 1e9;

//             dp[i][j] = min(up, min(leftDig, rightDig));
//         }
//     }
//     int maxi = INT_MAX;
//     for (int j = 0; j < m; j++)
//     {
//         maxi = min(maxi, dp[n - 1][j]);
//     }
//     return maxi;
// }
// int main()
// {

//     vector<vector<int>> grid{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

//     cout << pathSum(grid);
// }

// for maximum path

#include <bits/stdc++.h>
using namespace std;

int pathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = grid[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = grid[i][j] + dp[i - 1][j];

            int leftDig = grid[i][j];
            if (j - 1 >= 0)
                leftDig += dp[i - 1][j - 1];
            else
                leftDig += -1e9;

            int rightDig = grid[i][j];
            if (j + 1 < m)
                rightDig += dp[i - 1][j + 1];
            else
                rightDig += -1e9;

            dp[i][j] = max(up, max(leftDig, rightDig));
        }
    }
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }
    return maxi;
}
int main()
{

    vector<vector<int>> grid{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    cout << pathSum(grid);
}