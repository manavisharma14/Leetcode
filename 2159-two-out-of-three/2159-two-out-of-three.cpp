class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) { 
        vector<int>ans;
        unordered_map<int,int>freq;

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> set3(nums3.begin(), nums3.end());

        for(int num : set1){
            freq[num]++;
        }

        for(int num : set2){
            freq[num]++;
        }

        for(int num : set3){
            freq[num]++;
        }

        for(auto &[num, count]: freq){
            if(count >= 2){
                ans.push_back(num);
            }
        }
        return ans;
    }
};