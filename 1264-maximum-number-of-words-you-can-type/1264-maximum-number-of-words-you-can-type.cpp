class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        vector<string> words;
        while(ss>>word){
            words.push_back(word);
        }
        int cnt=0;
        for(string str:words){
            for(int i=0;i<brokenLetters.size();i++){
                if(str.find(brokenLetters[i])!=string::npos){
                    cnt++;
                    break;
                }
            }
        }
        return words.size()-cnt;
    }
};