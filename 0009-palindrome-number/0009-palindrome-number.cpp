
class Solution {
public:
    bool isPalindrome(int x) {
        string str=to_string(x);
        for(int i=0;i<(str.length()/2);i++){
            if(str[i]!=str[str.length()-1-i]){
                return false;
            }}
        return true;     
    }
};