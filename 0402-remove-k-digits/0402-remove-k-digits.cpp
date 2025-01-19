class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = ""; // Use this as a stack replacement

        for (char c : num) {
            // Remove characters from the result if they are greater than the current character
            // and we still have `k` digits to remove
            while (!result.empty() && k > 0 && result.back() > c) {
                result.pop_back();
                k--;
            }
            // Append the current character
            result.push_back(c);
        }

        // If we still have `k` digits left to remove, remove them from the end
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);

        // Return "0" if the result is empty
        return result.empty() ? "0" : result;
    }
};
