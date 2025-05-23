class Solution {
  public:
    // bool helper(int ind,int target,vector<int>& arr){
    //     if(target==0) return true;
    //     if(ind==0){
    //         return arr[0]==target;
    //     }
    //     bool notpick=helper(ind-1,target,arr);
    //     bool pick=false;
    //     if(target>=arr[ind]){
    //         pick=helper(ind-1,target-arr[ind],arr);
    //     }
    //     return pick || notpick;
    // }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
       if (arr[0] <= sum)
            dp[0][arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(target>=arr[i]){
                    pick=dp[i-1][target-arr[i]];
                }
                dp[i][target]=pick || notpick;
            }
        }
        return dp[n-1][sum];
    }
};