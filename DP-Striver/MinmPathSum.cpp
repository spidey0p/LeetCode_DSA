// #include <bits/stdc++.h>
// using namespace std;

// int MinmPath(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
// {
//     if (i == 0 && j == 0)
//         return grid[i][j];

//     if (i < 0 || j < 0)
//         return 1e9;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int up = grid[i][j] + MinmPath(i - 1, j, grid, dp);
//     int left = grid[i][j] + MinmPath(i, j - 1, grid, dp);

//     return dp[i][j] = min(up, left);
// }

// int minSumpath(int n, int m, vector<vector<int>> &grid)
// {
//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     return MinmPath(n - 1, m - 1, grid, dp);
// }

// int main()
// {
//     vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

//     int n = grid.size();
//     int m = grid[0].size();

//     cout << "Minimum weaight path is " << minSumpath(n, m, grid) << endl;
// }

/*Minimum weaight path is 7
T.C = O(N*M)
S.C = O((M-1)+(N-1)) + O(N*M)
*/

// Space optimization

#include <bits/stdc++.h>
using namespace std;

int minmSumPath(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];

            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;

                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left = +1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}
int main()
{
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    // vector<vector<int>> grid{{5, 9, 6}, {11, 5, 2}};

    int n = grid.size();
    int m = grid[0].size();

    cout << "Minimum weaight path is " << minmSumPath(n, m, grid);
}