// User function Template for C++
class Solution {
  public:
    void helper(vector<string>& ans, string str, int n, char lastChar) {
        if (str.size() == n) {
            ans.push_back(str);
            return;
        }

        // Always add '0'
        helper(ans, str + '0', n, '0');

        // Only add '1' if previous was not '1'
        if (lastChar != '1') {
            helper(ans, str + '1', n, '1');
        }
    }

    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        helper(ans, "", num, '0');  // Initial lastChar can be anything other than '1'
        return ans;
    }
};
