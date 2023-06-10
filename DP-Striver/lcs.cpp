#include <bits/stdc++.h>
using namespace std;
int myLove(string &str1, string &str2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 && ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (str1[ind1] == str2[ind2])
        return dp[ind1][ind2] = 1 + myLove(str1, str2, ind1 - 1, ind2 - 1, dp);
    else
        return dp[ind1][ind2] = 0 + max(myLove(str1, str2, ind1 - 1, ind2, dp), myLove(str1, str2, ind1, ind2 - 1, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return myLove(text1, text2, n - 1, m - 1, dp);
}