class Solution {
    public:
    void swap(int n,int x){
        int temp=n;
        n=x;
        x=temp;
    }
public:
    void moveZeroes(vector<int>& a) {
        //two pointer approach
        int j=-1;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return;
        for(int i=j+1;i<n;i++){
            if(a[i]!=0){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                j++;
            }
        }
    //  vector<int> temp;
    //  int n=nums.size();
    //  for(int i=0;i<n;i++){
    //     if(nums[i]!=0){
    //         temp.push_back(nums[i]);
    //     }
    //  }   
    //  int nz=temp.size();
    //  for(int i=0;i<nz;i++){
    //     nums[i]=temp[i];
    //  }
    //  for(int i=nz;i<n;i++){
    //     nums[i]=0;
    //  }
    }
};