#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end()); // Convert banned to a set for O(1) lookup
        int currentSum = 0;
        int count = 0;

        // Iterate through the range [1, n]
        for (int i = 1; i <= n; ++i) {
            if (bannedSet.count(i)) continue; // Skip banned numbers
            if (currentSum + i > maxSum) break; // Stop if adding i exceeds maxSum
            currentSum += i; // Add the number to the current sum
            count++; // Increment the count of selected numbers
        }

        return count;
    }
};
