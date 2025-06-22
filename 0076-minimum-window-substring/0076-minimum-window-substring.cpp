class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int> hash(256,0);
        for(int j=0;j<m;j++){
            hash[t[j]]++;
        }
        int r=0,l=0;
        int cnt=0;
        int minlen=INT_MAX;
        int sI=-1;
        while(r<n){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(minlen>(r-l+1)){
                    minlen=(r-l+1);
                    sI=l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;

                }
                l++;
            }
            r++;
        }
        return sI==-1 ? "" : s.substr(sI,minlen);
    }
};