class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;
        
        // Keep adding 'a' until repeated.length() >= b.length()
        while (repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        // Check if b is now a substring
        if (repeated.find(b) != string::npos) return count;

        // One more repetition might help (e.g., b = "aaac")
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) return count;

        return -1;
    }
};
