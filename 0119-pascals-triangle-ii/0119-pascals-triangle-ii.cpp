class Solution {
public:
    int generate(int n,int r){
        long long res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return (int)res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i=0;i<=rowIndex;i++){
            ans.push_back(generate(rowIndex,i));
        }
        return ans;
    }
};