class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1<<n;
        set<vector<int>> unique;
        sort(nums.begin(), nums.end()); 
        vector<vector<int>>ans;


        for(int num=0; num<subsets; num++){
            vector<int>list;
            for(int i=0; i<n; i++){
                if(num & (1<<i)){
                    list.push_back(nums[i]);
                }
            }
            sort(list.begin(), list.end());
            unique.insert(list);

        }
        return vector<vector<int>>(unique.begin(), unique.end());
    }
};