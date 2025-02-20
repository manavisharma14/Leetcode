class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n+1);

        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;


        vector<int>time(n+1,1e9);
        //distance src

        pq.push({0, k});
        time[k] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int node = it.second;

            for(auto iter: adj[node]){
                int adjnode = iter.first;
                int t = iter.second;

                if(time[adjnode] > t + time[node]){
                    time[adjnode] = time[node] + t;
                    pq.push({time[node] + t, adjnode});
                }
            }
        }
        
        int result = *max_element(time.begin() + 1, time.end());
        return result == 1e9? -1 : result;

    }
};