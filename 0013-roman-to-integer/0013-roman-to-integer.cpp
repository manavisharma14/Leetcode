class Solution {
public:
    int romanToInt(string s) {
     std::unordered_map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;

    // Iterate over the Roman numeral string from right to left
    for (int i = s.length() - 1; i >= 0; --i) {
        int currentValue = romanValues[s[i]];

        // If the current value is less than the previous value, subtract it
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            // Otherwise, add it
            result += currentValue;
        }

        // Update the previous value
        prevValue = currentValue;
    }

    return result;
}
};