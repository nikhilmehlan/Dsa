class Solution {
public:
    bool helper(string s, unordered_set<string>& wordSet,vector<int>& dp,int start){
        if(start==s.size()){
            return true;
        }

        if(dp[start]!=-1){
            return dp[start];
        }

        for(int end=start+1;end<=s.size();++end){
            if(wordSet.find(s.substr(start,end-start))!=wordSet.end() && helper(s,wordSet,dp,end)){
                return dp[start]=true;
            }
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());

        vector<int> dp(s.size(),-1);

        return helper(s,wordSet,dp,0);
    }
};