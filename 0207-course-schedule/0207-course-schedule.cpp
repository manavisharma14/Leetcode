#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);  // To store in-degrees
        vector<vector<int>> adj(numCourses); // Adjacency list
        vector<int> ans;                     // To store topological order
        vector<bool> visited(numCourses, false); // To track visited nodes

        // Build adjacency list and calculate in-degrees
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);  // pre[1] is prerequisite for pre[0]
            indegree[pre[0]]++;
        }

        queue<int> q;

        // Push all courses with in-degree 0 into the queue
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                visited[i] = true; // Mark as visited
            }
        }

        // Perform BFS
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ans.push_back(course); // Add to topological order

            for (int neighbor : adj[course]) {
                if (!visited[neighbor]) { // Check if not visited
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                        visited[neighbor] = true; // Mark as visited
                    }
                }
            }
        }

        // Check if the topological order contains all courses
        return ans.size() == numCourses;
    }
};
