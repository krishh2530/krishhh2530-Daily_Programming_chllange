#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    if (start == end) return 0;
    
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(V, false);
    queue<pair<int, int>> q;
    
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [node, distance] = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (neighbor == end) return distance + 1;
                visited[neighbor] = true;
                q.push({neighbor, distance + 1});
            }
        }
    }

    return -1;
}

int main() {
    int V1 = 5;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int start1 = 0, end1 = 4;
    cout << shortestPath(V1, edges1, start1, end1) << endl;

    int V2 = 3;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}};
    int start2 = 0, end2 = 2;
    cout << shortestPath(V2, edges2, start2, end2) << endl;

    int V3 = 4;
    vector<vector<int>> edges3 = {{0, 1}, {1, 2}};
    int start3 = 2, end3 = 3;
    cout << shortestPath(V3, edges3, start3, end3) << endl;

    return 0;
}
