#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjLs[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adjLs[node])
    {
        if (!vis[it])
        {
            dfs(it, adjLs, vis);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int v = isConnected.size();
    vector<int> adjLs[v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    vector<int> vis(v, 0);
    int cnt = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, adjLs, vis);
        }
    }
}
// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// private:
//     // dfs traversal function
//     void dfs(int node, vector<int> adjLs[], int vis[])
//     {
//         // mark the more as visited
//         vis[node] = 1;
//         for (auto it : adjLs[node])
//         {
//             if (!vis[it])
//             {
//                 dfs(it, adjLs, vis);
//             }
//         }
//     }

// public:
//     int numProvinces(vector<vector<int>> &isConnect)
//     {
//         int V = isConnect.size();
//         vector<int> adjLs[V];

//         // to change adjacency matrix to list
//         for (int i = 0; i < V; i++)
//         {
//             for (int j = 0; j < V; j++)
//             {
//                 // self nodes are not considered
//                 if (isConnect[i][j] == 1 && i != j)
//                 {
//                     adjLs[i].push_back(j);
//                     adjLs[j].push_back(i);
//                 }
//             }
//         }
//         int vis[V] = {0};
//         int cnt = 0;
//         for (int i = 0; i < V; i++)
//         {
//             // if the node is not visited
//             if (!vis[i])
//             {
//                 // counter to count the number of provinces
//                 cnt++;
//                 dfs(i, adjLs, vis);
//             }
//         }
//         return cnt;
//     }
// };

// int main()
// {

//     vector<vector<int>> adj{
//         {1, 0, 1},
//         {0, 1, 0},
//         {1, 0, 1}};

//     Solution ob;
//     cout << ob.numProvinces(adj, 3) << endl;

//     return 0;
// }