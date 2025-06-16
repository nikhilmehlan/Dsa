class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        if(colors[0]!=colors[n-1]){
            return n-1;
        }
        int alag=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(colors[i]!=colors[j]){
                    alag=max(alag,j-i);
                }
            }
        }
        return alag;
    }
};