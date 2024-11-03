
// 334. Increasing Triplet Subsequence
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    return true;
                }
            }
        }
        return false;
    }
};