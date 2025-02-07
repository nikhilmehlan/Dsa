class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freqMap;
        for(char task:tasks){
            freqMap[task]++;
        }
        priority_queue<int> maxHeap;
        for(auto& entry:freqMap){
            maxHeap.push(entry.second);
        }

        int time=0;
        while(!maxHeap.empty()){
            int cycle=n+1;
            vector<int> temp;

            for(int i=0;i<cycle && !maxHeap.empty();i++){
                temp.push_back(maxHeap.top()-1);
                maxHeap.pop();
            }

            for(int count:temp){
                if(count>0){
                    maxHeap.push(count);
                }
            }
            time+=maxHeap.empty() ? temp.size() : cycle;
        }
        return time;
    }
};