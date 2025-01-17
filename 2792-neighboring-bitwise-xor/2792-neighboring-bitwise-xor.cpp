class Solution {
public:
    bool isValid(vector<int>& derived, int org0){
        int n=derived.size();
        vector<int> original(n);
        original[0]=org0;

        for(int i=0;i<n-1;i++){
            original[i+1]=derived[i]^original[i];
        }

        return (derived[n-1]==original[n-1]^original[0]);

    }
    bool doesValidArrayExist(vector<int>& derived) {
        
        if(isValid(derived,0)) return true;
        if(isValid(derived,1)) return true;

        return false; 

    }
};