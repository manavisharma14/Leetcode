class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        std::priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>ans;

        for(int num: nums){
            freq[num]++;
        }

        for(auto &[num, freq]: freq){
            if(pq.size() < k){
                pq.push({freq, num});
            }
            else{
                if(freq > pq.top().first){
                    pq.pop();
                    pq.push({freq, num});
                }
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};