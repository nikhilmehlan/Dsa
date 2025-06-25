class Solution {
public:
    bool static comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
        int eraseOverlapIntervals(vector<vector<int>> & intervals) {
            if(intervals.size()==0) return 0;
            sort(intervals.begin(),intervals.end(),comparator);
            int prevE=intervals[0][1];

            int cnt=0;
            for(int i=1;i<intervals.size();i++){
                if(intervals[i][0]<prevE){
                    cnt++;
                }
                else{
                    prevE=intervals[i][1];
                }
            }
        
        return cnt;
    }
};