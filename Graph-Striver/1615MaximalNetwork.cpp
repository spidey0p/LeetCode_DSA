#include <bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<int> degree(n, 0);
    vector<vector<bool>> connected(n, vector<bool>(n, false));

    for (auto &it : roads)
    {
        int u = it[0];
        int v = it[1];

        degree[u]++;
        degree[v]++;

        connected[u][v] = true;
        connected[v][u] = true;
    }
    int maxRank = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int i_rank = degree[i];
            int j_rank = degree[j];

            int rank = i_rank + j_rank;
            if (connected[i][j])
            {
                rank--;
            }
            maxRank = max(maxRank, rank);
        }
    }
    return maxRank;
}