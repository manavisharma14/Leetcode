class Solution {
public:

    void dfs(vector<vector<int>>& adj, vector<int> &visited, int node, unordered_set<int>& nodes_in_comp, int &edge_count){
        visited[node] = 1;
        nodes_in_comp.insert(node);
        edge_count += adj[node].size();

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(adj, visited, neighbour, nodes_in_comp, edge_count);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int v = edges.size();
        vector<vector<int>>adj(n);

        int complete_components = 0;

        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>visited(n,0);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                unordered_set<int> nodes_in_comp;
                int edge_count=0;
                dfs(adj, visited, i, nodes_in_comp, edge_count);
                int k = nodes_in_comp.size();

                if(edge_count/2 == k*(k-1)/2){
                    complete_components++;
                }
            }
        }
        return complete_components;
    }
};