class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[low] <= nums[mid]){
                // left is the sorted array
                if(nums[low] <= target && nums[mid] > target){
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            } else if(nums[high] >= nums[mid]){
                // right is the sorted array
                if(nums[high] >= target && nums[mid] < target){
                    low = mid+1;
                } else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};