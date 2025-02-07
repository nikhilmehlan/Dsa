class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize !=0) return false;

        unordered_map<int,int> mpp;
        for(int card:hand){
            mpp[card]++;
        }

        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto& entry:mpp){
            pq.push(entry.first);
        }

        while(!pq.empty()){
            int first=pq.top();

            for(int i=0;i<groupSize;i++){
                int num=first+i;
                if(mpp[num]==0){
                    return false;
                }
                mpp[num]--;
                if(mpp[num]==0){
                    if(pq.top()==num){
                        pq.pop();
                    }
                }
            }
        }
        return true;
    }
};