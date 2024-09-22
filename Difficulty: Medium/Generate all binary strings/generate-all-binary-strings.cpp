//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateAllBinaryUtil(int n,int pos,string str,vector<string>& result){
        if(pos==n){
            result.push_back(str);
            return;
        }
        
        if(pos==0 || str[pos-1]=='0'){
            generateAllBinaryUtil(n,pos+1,str+'0',result);
            generateAllBinaryUtil(n,pos+1,str+'1',result);
        }
        else{
            generateAllBinaryUtil(n,pos+1,str+'0',result);
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string> result;
        if(num<=0) return result;
        generateAllBinaryUtil(num,0,"",result);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends