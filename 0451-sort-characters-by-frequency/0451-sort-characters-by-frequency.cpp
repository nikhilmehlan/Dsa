class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        string ans;
        priority_queue<pair<int,char>> maxHeap;
        for(auto count:mpp){
            maxHeap.push({count.second,count.first});
        }
        while(!maxHeap.empty()){
            auto top=maxHeap.top();
            maxHeap.pop();
            ans.append(top.first,top.second);
        }
        return ans;
    }
};