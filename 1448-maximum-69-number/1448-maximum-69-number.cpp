class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);  // convert to string for easy manipulation
        for (char &c : s) {
            if (c == '6') {  // change the first '6' to '9'
                c = '9';
                break;
            }
        }
        return stoi(s);  // convert back to int
    }
};
