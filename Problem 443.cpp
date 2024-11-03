//443. String Compression
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int count = 1;
        int n = chars.size();
        int writeIndex = 0;

        for (int i = 1; i < n; i++) {
            if (chars[i] == chars[i - 1]) {
                count++;
            } else {
                // Write the previous character
                chars[writeIndex++] = chars[i - 1];
                // If the count is greater than 1, write the count as well
                if (count > 1) {
                    for (char c : to_string(count)) {
                        chars[writeIndex++] = c;
                    }
                }
                // Reset the count for the new character
                count = 1;
            }
        }

        // Handle the last character
        chars[writeIndex++] = chars[n - 1];  // Write the last character
        if (count > 1) {
            for (char c : to_string(count)) {
                chars[writeIndex++] = c;  // Write the count if greater than 1
            }
        }

        return writeIndex;  // Return the new length of the compressed string
    }
};
