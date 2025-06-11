class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        string concat = s + s;
        if (concat.find(goal) != string::npos)
            return true;
        return false;
    }
};