// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        unordered_set<char> st;
        string ans;
        for(auto c:s){
            if(st.find(c)==st.end()){
                ans.push_back(c);
                st.insert(c);
            }
        }
        return ans;
    }
};