class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto val:mpp){
            if(val.second%2!=0){
                maxi=max(maxi,val.second);
            }
            else{
                mini=min(mini,val.second);
            }
        }
        return maxi-mini;
    }
};