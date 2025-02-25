class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(v);
        vector<int>indegree(v,0);

        for(auto &pre: prerequisites){
            int course = pre[0];
            int prerequisite = pre[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int>q;

        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        
        return count == v;
    }
};