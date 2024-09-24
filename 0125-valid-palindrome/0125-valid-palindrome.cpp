class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        
        while (start < end) {
            // Skip non-alphanumeric characters
            while (start < end && !isalnum(s[start])) {
                start++;
            }
            while (start < end && !isalnum(s[end])) {
                end--;
            }
            
            // Compare the current characters
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            
            // Move to the next characters
            start++;
            end--;
        }
        
        return true; // If all characters match
    }
};
