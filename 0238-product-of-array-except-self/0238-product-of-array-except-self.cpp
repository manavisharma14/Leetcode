class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n, 1);  // Create prefix array with all 1s
        vector<int> suffix(n, 1);  // Create suffix array with all 1s
        vector<int> product(n, 1); // Result array to store the final product

        for(int i=1; i<nums.size(); i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i=0; i<nums.size(); i++){
            product[i] = prefix[i]*suffix[i];
        }
        return product;
    }
};