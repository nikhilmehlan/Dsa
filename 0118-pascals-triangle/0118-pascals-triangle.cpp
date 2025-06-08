class Solution {
public:
    vector<int> gen(int row){
    vector<int> temp;
    int ans=1;
    temp.push_back(ans);
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/i;
        temp.push_back(ans);
    }
    return temp;
}
public:
    vector<vector<int>> generate(int N) {
         vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        ans.push_back(gen(i));
    }
    return ans;  
    }
};