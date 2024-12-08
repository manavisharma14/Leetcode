class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by their end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> dp(n, 0);
        vector<int> endTimes(n);

        // Extract end times for binary search
        for (int i = 0; i < n; i++) {
            endTimes[i] = events[i][1];
        }

        int maxValue = 0;
        int maxSingleEvent = 0; // Tracks the maximum value of a single event

        for (int i = 0; i < n; i++) {
            int startTime = events[i][0];
            int value = events[i][2];

            // Binary search to find the latest non-overlapping event
            int idx = upper_bound(endTimes.begin(), endTimes.end(), startTime - 1) - endTimes.begin() - 1;

            // Compute the maximum value for two non-overlapping events
            int currentValue = value;
            if (idx >= 0) {
                currentValue += dp[idx]; // Add the best non-overlapping value
            }

            // Update the global maximum
            maxValue = max(maxValue, currentValue);

            // Update maxSingleEvent and DP array
            maxSingleEvent = max(maxSingleEvent, value);
            dp[i] = maxSingleEvent; // Store the best single event value up to this point
        }

        return maxValue;
    }
};
