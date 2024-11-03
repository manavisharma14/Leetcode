// 238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
    int n = nums.size();
    std::vector<int> prefix(n, 1); // Initialize prefix product array with 1's
    std::vector<int> suffix(n, 1); // Initialize suffix product array with 1's

    prefix[0] = 1;
    suffix[n-1] = 1;

    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    for(int i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    std::vector<int> result(n);
    for(int i=0; i<n; i++){
        result[i] = prefix[i]*suffix[i];
    }
    
    return result;
    }
};