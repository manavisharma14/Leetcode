#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the adjacency list and indegree array
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // Edge from prerequisite to course
            indegrees[pre[0]]++;           // Increment indegree of the dependent course
        }

        // Queue for courses with no prerequisites
        queue<int> q;
        for (int course = 0; course < numCourses; ++course) {
            if (indegrees[course] == 0) {
                q.push(course);
            }
        }

        // Process the courses in topological order
        int completedCourses = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completedCourses++;

            for (int next_course : adj[course]) {
                indegrees[next_course]--;
                if (indegrees[next_course] == 0) {
                    q.push(next_course);
                }
            }
        }

        // Check if all courses can be completed
        return completedCourses == numCourses;
    }
};
