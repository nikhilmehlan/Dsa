class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
    vector<int> res(A.size());
    int p=0;int n=1;
    for(int i=0;i<A.size();i++){
        if(A[i]>0){
            res[p]=A[i];
            p+=2;
        }
        else{
            res[n]=A[i];
            n+=2;
        }
    }
    return res;
    }
};