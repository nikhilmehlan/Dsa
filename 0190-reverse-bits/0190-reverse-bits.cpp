class Solution {
public:
    int reverseBits(int n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++){
            ans=ans<<1;
            ans=ans | n& 1;
            n=n>>1;
        }
        return ans;
    }
};