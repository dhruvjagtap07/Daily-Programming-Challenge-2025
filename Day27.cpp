#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
You are given an unweighted graph represented by an adjacency list. Your task is to find
the shortest path (in terms of the number of edges) between two given nodes in the graph.

*/

class Solution
{
public:
    int shortestPath(int V, vector<vector<int>> &edges, int start, int end)
    {
        vector<vector<int>> graph(V);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (start == end)
            return 0;

        queue<pair<int, int>> q;
        vector<bool> visited(V, false);

        q.push({start, 0});
        visited[start] = true;

        while (!q.empty())
        {
            auto [node, dist] = q.front();
            q.pop();

            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    if (neighbor == end)
                        return dist + 1;
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    cout << sol.shortestPath(5, edges1, 0, 4) << endl;

    vector<vector<int>> edges2 = {{0, 1}, {1, 2}};
    cout << sol.shortestPath(3, edges2, 0, 2) << endl;

    vector<vector<int>> edges3 = {{0, 1}, {1, 2}};
    cout << sol.shortestPath(4, edges3, 2, 3) << endl;

    vector<vector<int>> edges4 = {};
    cout << sol.shortestPath(1, edges4, 0, 0) << endl;

    return 0;
}
