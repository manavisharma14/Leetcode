class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int x: nums){
            mp[x]++;
        }

        for(auto &p: mp){
            pq.push({p.second, p.first});
        }
        
        while(k--){
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};