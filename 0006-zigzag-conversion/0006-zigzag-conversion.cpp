class Solution {
public:
    string convert(string s, int numRows) {
    // If numRows is 1 or greater than or equal to the string length, return the original string.
    if (numRows == 1 || numRows >= s.length()) {
        return s;
    }

    vector<string> rows(min(numRows, (int)s.length())); // Create rows for the zigzag pattern.
    int currentRow = 0; // To keep track of the current row.
    bool goingDown = false; // To determine the direction of traversal.

    for (char c : s) {
        rows[currentRow] += c; // Append the current character to the corresponding row.
        // Change direction if we reach the top or bottom row.
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
        currentRow += goingDown ? 1 : -1; // Move up or down based on the direction.
    }

    string result;
    // Concatenate all rows to form the final zigzag string.
    for (string row : rows) {
        result += row;
    }

    return result;
}
};