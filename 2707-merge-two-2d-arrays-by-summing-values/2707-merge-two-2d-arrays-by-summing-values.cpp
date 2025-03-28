class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int>map;

        for(int i=0; i<nums1.size(); i++){
            int id = nums1[i][0];
            int val = nums1[i][1];

            map[id] +=val;
        }

        for(int i=0; i<nums2.size(); i++){
            int id = nums2[i][0];
            int val = nums2[i][1];

            map[id] +=val;
        }

        vector<vector<int>>result;
 
        for(auto &[id, val] : map){
            result.push_back({id,val});
        }

        sort(result.begin(), result.end());

    return result;
        
    }
};