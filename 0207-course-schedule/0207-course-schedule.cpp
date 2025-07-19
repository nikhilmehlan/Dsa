class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            ind[u]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()<numCourses) return false;

        return true;
    }
};