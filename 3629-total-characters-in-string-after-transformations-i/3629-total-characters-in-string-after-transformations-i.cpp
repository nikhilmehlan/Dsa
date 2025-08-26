class Solution {
public:
    const long long mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<vector<long long>> dp(26,vector<long long>(t+1,0));
        for(int i=0;i<26;i++){
            dp[i][0]=1;

        }

        for(int steps=1;steps<=t;steps++){
            for(int c=0;c<26;c++){
                if(c==25){
                    dp[25][steps]=(dp[0][steps-1]+dp[1][steps-1])%mod;
                }
                else{
                    dp[c][steps]=dp[c+1][steps-1]%mod;
                }
            }
        }
        long long ans=0;
        for(char c:s){
            ans=(ans+dp[c-'a'][t])%mod;
        }
        return (int)ans;
    }
};