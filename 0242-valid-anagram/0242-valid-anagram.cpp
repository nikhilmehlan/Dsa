class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> check(26,0);
        for(int i=0;i<s.length();i++){
            check[s[i]-'a']++;
            check[t[i]-'a']--;
        }
        for(int count:check){
            if(count!=0) return false;
        }
        return true;
    }
};