#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int T)
{
    int n = coins.size();

    vector<int> prev(T + 1, 0), cur(T + 1, 0);
}