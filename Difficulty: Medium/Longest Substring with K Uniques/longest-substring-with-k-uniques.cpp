class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int maxlen = -1;  // Initialize with -1 for "not found" case

        int right=0;
        int left=0;
        unordered_map<char,int> mpp;
        while(right<n){
            mpp[s[right]]++;
            if(mpp.size()>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
                left++;
            }
            if(mpp.size()==k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};
