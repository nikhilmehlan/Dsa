class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s(version1);
        stringstream t(version2);
        vector<string> temp1;
        vector<string> temp2;
        string token;
        while(getline(s,token,'.')){
            temp1.push_back(token);
        }
        while(getline(t,token,'.')){
            temp2.push_back(token);
        }
        int maxi=max(temp1.size(),temp2.size());
        for(int i=0;i<maxi;i++){
            int val1=0;
            if(i<temp1.size()){
                val1=stoi(temp1[i]);
            }
            int val2=0;
            if(i<temp2.size()){
                val2=stoi(temp2[i]);
            }
            
            if(val1==val2) continue;
            else if(val1 > val2) return 1;
            else if(val1 < val2) return -1;
        }
        return 0;
    }
};