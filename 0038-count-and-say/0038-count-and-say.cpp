class Solution {
public:
    string countAndSay(int n) {
        string result="1";
        for(int j=2;j<=n;j++){
            string current="";
            int cnt=1;
            char prev=result[0];
            for(int i=1;i<result.size();i++){
                if(result[i]==prev) cnt++;
                else{
                    current+=to_string(cnt)+prev;
                    cnt=1;
                    prev=result[i];
                }
            }
            current+=to_string(cnt)+prev;
            result=current;

        }
        return result;
    }
};