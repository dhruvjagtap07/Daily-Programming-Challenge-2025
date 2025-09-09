#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
You are given an undirected graph represented by an adjacency list. Your task is to determine if the graph
contains any cycle. A cycle is formed if you can traverse through a sequence of edges that starts and ends
at the same vertex, with at least one edge in between.
*/

class Solution
{
public:
    bool containsCycle(int V, vector<pair<int, int>> &edges)
    {
        // Build adjacency list
        vector<vector<int>> graph(V);
        for (auto &e : edges)
        {
            int u = e.first, v = e.second;
            graph[u].push_back(v);
            graph[v].push_back(u); // undirected
        }

        vector<bool> visited(V, false);

        function<bool(int, int)> dfs = [&](int node, int parent)
        {
            visited[node] = true;
            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    if (dfs(neighbor, node))
                        return true;
                }
                else if (neighbor != parent)
                {
                    return true; // cycle detected
                }
            }
            return false;
        };

        // Check all components
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;

    int V1 = 5;
    vector<pair<int, int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    cout << boolalpha << sol.containsCycle(V1, edges1) << endl; // true

    int V2 = 3;
    vector<pair<int, int>> edges2 = {{0, 1}, {1, 2}};
    cout << sol.containsCycle(V2, edges2) << endl; // false

    int V3 = 4;
    vector<pair<int, int>> edges3 = {{0, 1}, {1, 2}, {2, 0}};
    cout << sol.containsCycle(V3, edges3) << endl; // true

    int V4 = 3;
    vector<pair<int, int>> edges4 = {{0, 1}, {0, 1}};
    cout << sol.containsCycle(V4, edges4) << endl; // true (parallel edges)
}
