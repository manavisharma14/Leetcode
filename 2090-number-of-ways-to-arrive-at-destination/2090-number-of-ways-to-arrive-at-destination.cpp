#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Build adjacency list (bidirectional)
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Initialize distance and ways arrays
        vector<long long> distance(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int mod = (int)(1e9 + 7);

        // Starting node
        ways[0] = 1;
        distance[0] = 0;
        pq.push({0, 0});

        // Dijkstra's Algorithm
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            long long dist = it.first;
            int node = it.second;

            if (dist > distance[node]) continue;  // Skip if already visited with a shorter distance

            for (auto iter : adj[node]) {
                int adjnode = iter.first;
                long long t = iter.second;

                // Found a shorter path
                if (distance[adjnode] > distance[node] + t) {
                    distance[adjnode] = distance[node] + t;
                    ways[adjnode] = ways[node];  // Inherit the number of ways from the current node
                    pq.push({distance[adjnode], adjnode});
                }
                // Found another shortest path
                else if (distance[adjnode] == distance[node] + t) {
                    ways[adjnode] = (ways[node] + ways[adjnode]) % mod;  // Accumulate the number of ways
                }
            }
        }

        // Return the number of ways to reach the last node
        return ways[n - 1] % mod;
    }
};
