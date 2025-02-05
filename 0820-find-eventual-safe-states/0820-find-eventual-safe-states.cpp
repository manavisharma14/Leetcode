class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<vector<int>>adjrev(v);
        vector<int>indegree(v,0);

        for(int i=0 ;i<v; i++){
            for(auto it: adj[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;

        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>safenodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);

            for(auto it : adjrev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(safenodes.begin(), safenodes.end());
        return safenodes;

    }
};