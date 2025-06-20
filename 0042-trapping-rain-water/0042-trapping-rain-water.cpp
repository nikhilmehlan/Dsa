class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1;
        int mr=0;
        int ml=0;
        int res=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=ml){
                    ml=height[left];
                }
                else{
                    res+=ml-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=mr){
                    mr=height[right];
                }
                else{
                    res+=mr-height[right];

                }
                right--;
            }
        }
        return res;
    }
};