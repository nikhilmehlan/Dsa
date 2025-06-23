class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        unordered_map<int, int> mpp;
        for (auto it : hand) {
            mpp[it]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : mpp) {
            pq.push(it.first);
        }
        while (!pq.empty()) {
            int first = pq.top();
            for (int i = 0; i < groupSize; i++) {
                int num = first + i;
                if (mpp[num] == 0)
                    return false;
                mpp[num]--;
                if (mpp[num] == 0) {
                    if (num== pq.top()) {
                        pq.pop();
                    }
                }
            }
        }
        return true;
    }
};