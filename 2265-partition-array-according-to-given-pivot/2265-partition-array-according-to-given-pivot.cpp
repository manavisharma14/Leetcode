class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>left;
        vector<int>right;
        vector<int>middle;

        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                left.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                right.push_back(nums[i]);
            }
            else{
                middle.push_back(nums[i]);
            }
        }

        left.insert(left.end(), middle.begin(), middle.end());
        left.insert(left.end(), right.begin(), right.end());

        return left;

    }
};