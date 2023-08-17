#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph)
{
    color[node] = col; // color the current node
    for (auto it : graph[node])
    {
        if (color[it] == col)
            return false; // found an iinconsistancy in coloring
        if (color[it] == 0 && !dfs(node, -col, color, graph))
            return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<int> color(v);
    for (int i = 0; i < v; i++)
        color[i] = -1;
    for (int i = 0; i < v; i++)
    {
        if (color[i] == 0 && !dfs(i, 1, color, graph))
        {
            return false;
        }
    }
    return true;
}