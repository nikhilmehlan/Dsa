class Solution {
public:
    bool static comparator(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comparator);

        int cnt=0;
        int limit=intervals[0][1];

        for(int i=1;i<n;i++){
            if(limit>intervals[i][0]){
                cnt++;
            }
            else{
                limit=intervals[i][1];
            }
        }
        return cnt;
    }
};