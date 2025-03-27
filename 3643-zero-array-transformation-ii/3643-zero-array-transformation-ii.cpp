class Solution {
public:
    bool canZeroWithK(int k, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);

        for (int i = 0; i < k; ++i) {
            int left = queries[i][0];
            int right = queries[i][1];
            int val = queries[i][2];

            diff[left] += val;
            diff[right + 1] -= val;
        }

        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (diff[i] < (long long)nums[i]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0;
        int right = queries.size();
        int answer = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canZeroWithK(mid, nums, queries)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
