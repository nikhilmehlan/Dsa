class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        while (str.size() <= k) {  // Fix 1: should be `<=` not `>`, and reversed logic
            string temp = "";
            for (int i = 0; i < str.size(); i++) {
                temp += (char)(str[i] + 1);  // Fix 2: convert to next char instead of using `to_string(str[i]+1)`
            }
            str += temp;
        }
        return str[k-1];  // Fix 3: index is already 0-based, so use `str[k]`
    }
};
