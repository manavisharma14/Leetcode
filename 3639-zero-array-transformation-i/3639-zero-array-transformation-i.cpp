class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n+1, 0);

        for(auto& query : queries){
            int left = query[0];
            int right = query[1];

            diff[left] += 1;
            if(right+1 < n + 1){
                diff[right+1] -= 1;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(i>0){
                diff[i] += diff[i-1];
            }
            if(diff[i] < nums[i]){
                return false;
            }
        }

        
    return true;
        
    }
};