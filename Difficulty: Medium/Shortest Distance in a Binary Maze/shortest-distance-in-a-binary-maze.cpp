//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> dest) {
        // code here
        if(source == dest) return 0;
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 
                && dis+1 <dist[newr][newc]){
                    dist[newr][newc]=dis+1;
                    if(newr==dest.first && newc==dest.second) return dis+1;
                    
                    q.push({dis+1,{newr,newc}});
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends