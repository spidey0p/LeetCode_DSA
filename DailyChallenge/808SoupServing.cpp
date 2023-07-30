#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> serves = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
// for Memozation
vector<vector<double>> dp;
double solve(double A, double B)
{
    if (A <= 0 && B <= 0)
        return 0.5;

    if (A <= 0)
        return 1.0;

    if (B <= 0)
        return 0.0;

    if (dp[A][B] != -1)
        return dp[A][B];
    double prob = 0.0;

    for (auto &p : serves)
    {
        int A_take = p.first;
        int B_take = p.second;

        prob += solve(A - A_take, B - B_take);
    }
    return dp[A][B] = 0.25 * prob;
}

double soupServings(int n)
{
    return solve(n, n);
}