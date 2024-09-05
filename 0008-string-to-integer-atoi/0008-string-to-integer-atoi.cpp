#include <string>
#include <cctype> // For isdigit
#include <iostream>
#include <stdexcept> // For std::invalid_argument

class Solution {
public:
    int myAtoi(std::string s) {
        std::string ans = "";
        bool hasSign = false; // To track if the number has a sign

        for (char c : s) {
            if (c == ' ') {
                if (!ans.empty() || hasSign) {
                    // If we already have characters in ans or a sign, break on space
                    break;
                }
                continue;
            } else if (c == '-') {
                if (hasSign || !ans.empty()) {
                    // A negative sign should be the first non-space character
                    break;
                }
                ans.push_back(c);
                hasSign = true;
            } else if (c == '+') {
                if (hasSign || !ans.empty()) {
                    // A positive sign should be the first non-space character
                    break;
                }
                hasSign = true; // Positive sign does not need to be stored
            } else if (std::isdigit(c)) {
                ans.push_back(c);
            } else {
                break;
            }
        }

        // If ans is empty or only has a sign, return 0
        if (ans.empty() || (ans.size() == 1 && (ans[0] == '-' || ans[0] == '+'))) {
            return 0;
        }

        try {
            return std::stoi(ans);
        } catch (const std::out_of_range& e) {
            // Handle overflow and underflow cases
            if (ans[0] == '-') {
                return std::numeric_limits<int>::min();
            } else {
                return std::numeric_limits<int>::max();
            }
        } catch (const std::invalid_argument& e) {
            // This case should be covered by the empty check above
            return 0;
        }
    }
};


