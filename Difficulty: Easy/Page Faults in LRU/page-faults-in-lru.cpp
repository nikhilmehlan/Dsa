//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_set<int> memory;
        list<int> lru;
        int cnt=0;
        for(int i=0;i<N;i++){
            int page=pages[i];
            
            if(memory.find(page)==memory.end()){
                cnt++;
                
                
                if(memory.size()==C){
                    int p=lru.front();
                    lru.pop_front();
                    memory.erase(p);
                }
            }
            else{
                lru.remove(page);
            }
            lru.push_back(page);
            memory.insert(page);
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends