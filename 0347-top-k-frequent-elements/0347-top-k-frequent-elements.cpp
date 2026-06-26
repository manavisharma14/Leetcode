class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;

        for (int num: nums){
            mp[num]++;
        }

        for (auto& it : mp){
            pq.push({it.second, it.first});
        }
        
        vector<int>ans;

        while(k>0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};