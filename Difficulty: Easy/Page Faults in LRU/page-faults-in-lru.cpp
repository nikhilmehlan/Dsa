// User function Template for C++

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        unordered_set<int> memory;
        list<int> lt;
        int cnt=0;
        for(int i=0;i<N;i++){
            int page=pages[i];
            if(memory.find(page)==memory.end()){
                cnt++;
                if(memory.size()==C){
                    int p=lt.front();
                    lt.pop_front();
                    memory.erase(p);
                }
            }
                else{
                    lt.remove(page);
                }
                lt.push_back(page);
                memory.insert(page);
            
        }
        return cnt;
    }
};