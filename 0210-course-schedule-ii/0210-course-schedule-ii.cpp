#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Build the graph and the indegree array
        for (auto& pre : prerequisites) {
            int prerequisite = pre[1];
            int course = pre[0];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push all courses with no prerequisites into the queue
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        // Process the courses
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            topoOrder.push_back(course);

            // For each dependent course, reduce its indegree
            for (int next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If we have processed all courses, return the order
        if (topoOrder.size() == numCourses) {
            return topoOrder;
        }
        return {};
    }
};
