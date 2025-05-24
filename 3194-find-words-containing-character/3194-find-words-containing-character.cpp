class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char ch) {
        vector<int> ans;
        int cnt=0;
        for(string str:words){
            if (str.find(ch) != string::npos){
                ans.push_back(cnt);
            }
            cnt++;
        }
        return ans;
    }
};