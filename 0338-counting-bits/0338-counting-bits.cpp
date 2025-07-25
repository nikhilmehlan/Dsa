class Solution {
public:
    int helper(int n){
        int cnt=0;
        while(n!=0){
            n=n&n-1;
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;i++){
            int val=helper(i);
            result.push_back(val);
        }
        return result;
    }
};