class Solution {
public:
int func(vector<int>& arr,int x){
	int n=arr.size();
	int total=0;
	for(int i=0;i<n;i++){
		total+=ceil((double)arr[i]/double(x));
	}
	return total;
}
public:
    int smallestDivisor(vector<int>& arr, int limit) {
    int n=arr.size();
    if(n>limit) return -1;
	int low=1;
	int high=*max_element(arr.begin(),arr.end());
	while(low<=high){
		int mid=(low+high)/2;
		int val=func(arr,mid);
		if(val<=limit){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return low;
    }
};