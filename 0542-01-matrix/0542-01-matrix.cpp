class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int row=top.first.first;
            int col=top.first.second;
            int steps=top.second;
            ans[row][col]=steps;

            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    q.push({{nr,nc},steps+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return ans;
    }
};