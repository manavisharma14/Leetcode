class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int>map1;

        for(auto& num: nums1){
            int id = num[0];
            int val = num[1];
            map1[id] += val;
        }

        for(auto& num: nums2){
            int id = num[0];
            int val = num[1];
            map1[id] += val;
        }

        vector<vector<int>>result;

        for(auto& [id, val] : map1){
            result.push_back({id,val});
        }
        sort(result.begin(), result.end());
        return result;
    }
};