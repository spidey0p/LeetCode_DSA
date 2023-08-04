#include <bits/stdc++.h>
using namespace std;

int editDistance(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 0 + editDistance(s1, s2, i - 1, j - 1, dp);

    else
        return dp[i][j] = 1 + min(editDistance(s1, s2, i - 1, j - 1, dp), min(editDistance(s1, s2, i - 1, j, dp), editDistance(s1, s2, i, j - 1, dp)));
}

int minDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return editDistance(word1, word2, m - 1, n - 1, dp);
}