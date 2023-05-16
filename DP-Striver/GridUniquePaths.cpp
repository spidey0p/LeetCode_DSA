#include <bits/stdc++.h>
using namespace std;

int countWay(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = countWay(i - 1, j, dp);
    int left = countWay(i, j - 1, dp);

    return dp[i][j] = down + left;
}

int countTotalWay(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countWay(m - 1, n - 1, dp);
}

int main()
{
    int m, n;
    cout << "Enter Rows and columns respectively:" << endl;
    cin >> m >> n;
    cout << "Total number of ways: ";
    cout << countTotalWay(m, n) << endl;
}
/*Enter Rows and columns respectively:
7 3
Total number of ways: 28*/
