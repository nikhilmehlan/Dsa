int pageCount(vector<int>& arr,int pages){
    int student=1;
    int pC=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+pC<=pages){
            pC+=arr[i];
        }
        else{
            student++;
            pC=arr[i];
        }
    }
    return student;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int val=pageCount(arr,mid);
        if(val>m){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}