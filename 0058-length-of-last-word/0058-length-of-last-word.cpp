class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        // Skip trailing spaces
        while(i >= 0 && s[i] == ' ') i--;

        // Count the last word
        while(i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
