class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,char> mapST;
        unordered_map<char,char> mapTS;
        for(int i=0;i<s.length();i++){
            char cs=s[i];
            char ct=t[i];

            if(mapST.find(cs)!=mapST.end()){
                if(mapST[cs]!=ct){
                    return false;
                }
            }
            else{
                mapST[cs]=ct;
            }
            if(mapTS.find(ct)!=mapTS.end()){
                if(mapTS[ct]!=cs){
                    return false;
                }
            }
            else{
                mapTS[ct]=cs;
            }
        }
    return true;
    }
};