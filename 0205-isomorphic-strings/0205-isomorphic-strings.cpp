class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() !=t.size()) return false;
        unordered_map<char,char> mppst;
        unordered_map<char,char> mppts;
        for(int i=0;i<s.size();i++){
            char st=s[i];
            char ts=t[i];
            if(mppst.find(st)!=mppst.end()){
                if(mppst[st]!=ts) return false;
            }
            else{
                mppst[st]=ts;
            }
            if(mppts.find(ts)!=mppts.end()){
                if(mppts[ts]!=st) return false;
            }
            else{
                mppts[ts]=st;
            }
        }
    return true;
    }
};