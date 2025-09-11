class Solution {
public:
    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }

    string sortVowels(string s) {
        vector<char> vowels;

        // Step 1: Extract vowels
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Step 2: Sort vowels
        sort(vowels.begin(), vowels.end());

        // Step 3: Place vowels back
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[index++];
            }
        }

        return s;
    }
};
