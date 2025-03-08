class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minWhite = k; // Maximum we may need to recolor
        int whiteCount = 0;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                whiteCount++;
            }
        }

        minWhite = whiteCount;

        // Slide the window
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') {
                whiteCount--; // Remove leftmost element of the window
            }
            if (blocks[i] == 'W') {
                whiteCount++; // Add rightmost element of the window
            }

            minWhite = min(minWhite, whiteCount);
        }

        return minWhite;
    }
};
