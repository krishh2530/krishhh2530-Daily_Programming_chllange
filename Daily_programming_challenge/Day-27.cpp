#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adj(V);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (node == end) return dist;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int start = 0, end = 4;

    int result = solution.shortestPath(V, edges, start, end);
    if (result != -1) {
        cout << "The shortest path length is: " << result << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}