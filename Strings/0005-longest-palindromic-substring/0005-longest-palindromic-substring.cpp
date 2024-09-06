class Solution {
public:
    string check(string s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
public:
    string longestPalindrome(string s) {
        if(s.length()==0){
            return "";
        }
        string longest="";
        for(int i=0;i<s.length();i++){
            string odd=check(s,i,i);
            if(odd.length()>longest.length()){
                longest=odd;
            }
            string even=check(s,i,i+1);
            if(even.length()>longest.length()){
                longest=even;
            }
        }
    return longest;
    }
};