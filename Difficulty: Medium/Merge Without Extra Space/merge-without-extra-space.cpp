class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int left=a.size()-1;
        int right=0;
        while(left>=0 && right<b.size()){
            if(a[left]>b[right]){
                std::swap(a[left],b[right]);
                left--;
                right++;
            }
            else{
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};