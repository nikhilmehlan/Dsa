class Solution {
public:
    bool rotateString(string s, string goal) {
            if (s.length() != goal.length()) {
            return false; // If lengths are not equal, return false immediately
        }

         string concat=s+s;
         if(concat.find(goal)!=string::npos){
            return true;
         }
         return false;
    }
};