class Solution{
public:
    // Function to find the first occurrence of the target
    int findfirst(int nums[], int n, int target){
        int low = 0;
        int high = n - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;  // Update ans as we are looking for the first occurrence
                high = mid - 1;  // Move left to check for earlier occurrences
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // Function to find the last occurrence of the target
    int findlast(int nums[], int n, int target){
        int low = 0;
        int high = n - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;  // Update ans as we are looking for the last occurrence
                low = mid + 1;  // Move right to check for later occurrences
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // Function to count occurrences of target `x` in the array
    int count(int arr[], int n, int x) {
        int first = findfirst(arr, n, x);
        int last = findlast(arr, n, x);
        
        // If the element is not present in the array, return 0
        if (first == -1) return 0;
        
        // Return the count of occurrences
        return (last - first + 1);
    } 
	
};