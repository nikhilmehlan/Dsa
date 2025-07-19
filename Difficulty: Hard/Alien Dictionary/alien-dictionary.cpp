class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char,int> ind;
        unordered_map<char,vector<char>> graph;
        
        for(auto it:words){
            for(char c:it){
                ind[c]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string str1=words[i];
            string str2=words[i+1];
            int len=min(str1.size(),str2.size());
            
            bool found=false;
            for(int i=0;i<len;i++){
                if(str1[i]!=str2[i]){
                    graph[str1[i]].push_back(str2[i]);
                    ind[str2[i]]++;
                    found=true;
                    break;
                }
            }
            
            if(!found && str1.size()> str2.size()){
                return "";
            }
        }
        queue<char> q;
        for(auto it:ind){
            if(it.second==0){
                q.push(it.first);
            }
        }
        string res="";
        while(!q.empty()){
            auto ch=q.front();
            q.pop();
            res+=ch;
            for(auto it:graph[ch]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(res.size()!=ind.size()) return "";
        
        return res;
    }
};