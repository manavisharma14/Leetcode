class Solution {
public:

    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i]) continue; // Skip already used elements
        visited[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, visited, current, result);
        current.pop_back(); // Backtrack
        visited[i] = false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> visited(nums.size(), false);
    backtrack(nums, visited, current, result);
    return result;
}
};