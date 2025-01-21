class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();

        vector<long long> top(n+1,0),bottom(n+1,0);
        for(int i=0;i<n;i++){
            top[i+1]=top[i]+grid[0][i];
            bottom[i+1]=bottom[i]+grid[1][i];
        }

        long long result=LLONG_MAX;

        for(int i=0;i<n;i++){
            long long toppoints=top[n]-top[i+1];
            long long bottompoints=bottom[i];

            long long result2=max(toppoints,bottompoints);

            result=min(result,result2);
        }
    return result;
    }
};