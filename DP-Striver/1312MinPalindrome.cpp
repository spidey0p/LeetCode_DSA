#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int longestPalindromicSubscquence(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}
int minInsertions(string s)
{
    int n = s.size();
    int k = longestPalindromicSubscquence(s);
    return n - k;
}