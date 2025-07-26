class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s(nums.begin() , nums.end());
        int ans = 0;
        for(int num : s){
            if(s.find(num-1) == s.end()){
                int curr = num;
                int count = 0;
                while(s.find(curr) != s.end()){
                    curr++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};