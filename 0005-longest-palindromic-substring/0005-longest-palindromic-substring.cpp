class Solution {
public:
    string palindrome(string s,int left,int right){
        while(left>=0 && right<=s.size()-1 && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        string longest="";
        for(int i=0;i<s.size();i++){
            string odd=palindrome(s,i,i);
            if(odd.size()>longest.size()){
                longest=odd;
            }
            string even=palindrome(s,i,i+1);
            if(even.size()>longest.size()){
                longest=even;
            }
        }
        return longest;
    }
};