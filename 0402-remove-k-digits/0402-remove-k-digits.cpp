class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";

        for (char c : num) {
            while (!result.empty() && result.back() > c && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(c);  // Don't forget to add the current digit
        }

        // Remove remaining digits from the end if k > 0
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

        return result.empty() ? "0" : result;
    }
};
