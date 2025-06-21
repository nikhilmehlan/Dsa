class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right=0;
        int left=0;
        int maxlen=0;
        vector<int> hash(256,0);
        while(right<s.size()){
            if(hash[s[right]]==0){
                hash[s[right]]=1;
                int len=right-left+1;
                maxlen=max(maxlen,len);
                right++;
            }
            else{
                hash[s[left]]=0;
                left++;
            }
        }
        return maxlen;
    }
};