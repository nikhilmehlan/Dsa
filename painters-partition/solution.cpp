int func(vector<int> arr,int b){
    int cnt=1;
    int bc=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+bc<=b){
            bc+=arr[i];
        }
        else{
            cnt++;
            bc=arr[i];
        }
    }
    return cnt;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    if(k>boards.size()) return -1;
    int maxi=*max_element(boards.begin(),boards.end());
    int sum=accumulate(boards.begin(),boards.end(),0);
    int low=maxi;
    int high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        int val=func(boards,mid);
        if(val>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
        return low;
}