//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class disjointSet{
    private:
    vector<int> parent,rank;
    public:
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    
    int findUpar(int x){
        if(x==parent[x]) return x;
        
        return parent[x]=findUpar(parent[x]);
    }
    
    void unionbyRank(int u,int v){
        int upu=findUpar(u);
        int upv=findUpar(v);
        if(upu==upv) return;
        if(upu<upv){
            parent[upu]=upv;
        }
        else if(upu>upv){
            parent[upv]=upu;
            
        }
        else{
            parent[upv]=upu;
            rank[upu]++;
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,pair<int,int>>> adj(V);
        for(auto it:edges){
            adj.push_back({it[2],{it[0],it[1]}});
        }
        
        disjointSet ds(V);
        int mswt=0;
        sort(adj.begin(),adj.end());
        for(auto edge:adj){
            int wt=edge.first;
            int u=edge.second.first;
            int v=edge.second.second;
            
            if(ds.findUpar(u)!=ds.findUpar(v)){
                mswt+=wt;
                ds.unionbyRank(u,v);
            }
        }
        return mswt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        Solution obj;
        cout << obj.kruskalsMST(V, edges) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends