class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss>>word){
            words.push_back(word);
        }
        reverse(words.begin(),words.end());
        string ans="";
        int n=words.size();
        for(int i=0;i<n-1;i++){
            ans+=words[i];
            ans+=" ";
        }
        ans+=words[n-1];
        return ans;
    }
};