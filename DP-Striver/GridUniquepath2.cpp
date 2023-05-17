// #include <bits/stdc++.h>
// using namespace std;

// int countWays(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp)
// {
//     if (i > 0 && j > 0 && maze[i][j] == -1)
//         return 0;
//     if (i == 0 && j == 0)
//         return 1;
//     if (i < 0 || j < 0)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int down = countWays(i - 1, j, maze, dp);
//     int left = countWays(i, j - 1, maze, dp);

//     return dp[i][j] = down + left;
// }

// int obstacles(int n, int m, vector<vector<int>> &maze)
// {
//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     return countWays(n - 1, m - 1, maze, dp);
// }

// int main()
// {
//     vector<vector<int>> maze{{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};

//     int n = maze.size();    // number of rows in the maze
//     int m = maze[0].size(); // number of columns in the maze
//     cout << obstacles(n, m, maze);
//     return 0;
// }

/*T.C = O(N*M)
S.C = O((M-1)+(N-1)) + O(N*M)
*/

// Tebalution method

// #include <bits/stdc++.h>
// using namespace std;

// int countWays(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {

//             if (i > 0 && j > 0 && maze[i][j] == -1)
//             {
//                 dp[i][j] = 0;
//                 continue;
//             }
//             if (i == 0 && j == 0)
//             {
//                 dp[i][j] = 1;
//                 continue;
//             }
//             int up = 0;
//             int left = 0;
//             if (i > 0)
//             {
//                 up = dp[i - 1][j];
//             }
//             if (j > 0)
//             {
//                 left = dp[i][j - 1];
//             }
//             dp[i][j] = up + left;
//         }
//     }
//     return dp[n - 1][m - 1];
// }

// int obstacles(int n, int m, vector<vector<int>> &maze)
// {
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return countWays(n, m, maze, dp);
// }

// int main()
// {
//     vector<vector<int>> maze{{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
//     int n = maze.size();
//     int m = maze[0].size();

//     cout << obstacles(n, m, maze) << endl;
//     return 0;
// }

/*
T.C = O(M*N)
S.C = O(M*N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (i > 0 && j > 0 && maze[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
        return dp[n - 1][m - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &maze)
    {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        return countWays(n, m, maze, dp);
    }
};
int main()
{
    vector<vector<int>> maze{{0, 1}, {0, 0}};
    int n = maze.size();
    int m = maze[0].size();
    cout << n << " " << m;
    Solution S;
    int ans = S.uniquePathsWithObstacles(maze);
    cout << ans << endl;
    return 0;
}