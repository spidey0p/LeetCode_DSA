#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int row, int col, int &n, int &m, int &area)
    {
        area++;
        grid[row][col] = 0;

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
            {
                dfs(grid, nrow, ncol, n, m, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    dfs(grid, i, j, n, m, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
