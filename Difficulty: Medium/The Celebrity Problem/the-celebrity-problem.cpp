class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int res=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            if(mat[res][i]==1){
                res=i;
            }
        }
        bool isCeleb=true;
        for(int i=0;i<n;i++){
            if(res!=i && (mat[res][i]==1 || mat[i][res]==0)){
                isCeleb=false;
                break;
            }
        }
        if(isCeleb) return res;
        return -1;
    }
};