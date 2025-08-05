class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        pair<int, int> p;
        int maxi=0;

        for(int i=0; i<m; i++){
            int c=0;
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    c++;
                    if(c>maxi){
                        maxi=c;
                        p.first=i;
                        p.second=maxi;
                    }
                }
            }
        }

        return {p.first, p.second};
    }
};