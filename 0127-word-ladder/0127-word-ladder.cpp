class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        q.push({beginWord,1});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            string word=node.first;
            int steps=node.second;
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char x='a';x<='z';x++){
                    word[i]=x;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};