//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        vector<long long int> ans;
        long XOR=0;
        for(int i=0;i<n;i++){
            XOR=XOR^arr[i];
        }
        long right=(XOR & XOR-1)^ XOR;
        // long right=XOR & -XOR;
        long b1=0;
        long b2=0;
        for(int i=0;i<n;i++){
            if(arr[i] & right){
                b1=b1^arr[i];
            }
            else{
                b2=b2^arr[i];
            }
        }
        ans.push_back(b1);
        ans.push_back(b2);
        sort(ans.begin(),ans.end(),greater<long long int>());
        return ans;
    }
};
