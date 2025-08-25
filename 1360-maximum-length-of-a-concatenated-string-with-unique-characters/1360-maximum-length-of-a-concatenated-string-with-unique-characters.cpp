class Solution {
public:
    // check if s1 and s2 can be concatenated without duplicate chars
    bool canConcat(string& s1, string& s2) {
        vector<int> freq(26, 0);

        for (char c : s1) {
            if (freq[c - 'a']++) return false; // duplicate in s1
        }

        for (char c : s2) {
            if (freq[c - 'a']++) return false; // duplicate in s2 or overlap
        }

        return true;
    }

    int solve(vector<string>& arr, string temp, int i, int n) {
        if (i == n) return temp.length();

        int exclude = solve(arr, temp, i + 1, n);
        int include = 0;

        if (canConcat(temp, arr[i])) {
            include = solve(arr, temp + arr[i], i + 1, n);
        }

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        return solve(arr, "", 0, arr.size());
    }
};

