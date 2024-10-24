//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {

 int count = 0;  // To store the total count of set bits
    int i = 0;      // i represents the bit position

    // Loop through each bit position from 0 to the most significant bit in n
    while ((1 << i) <= n) {
        // Calculate the number of full cycles of 0s and 1s for the ith bit position
        int total_pairs = (n + 1) / (1 << (i + 1));

        // Add the number of set bits contributed by these full cycles
        count += total_pairs * (1 << i);

        // Calculate the remainder to check if there are extra set bits in the last partial cycle
        int remainder = (n + 1) % (1 << (i + 1));
        count += max(0, remainder - (1 << i));

        // Move to the next bit position
        i++;
    }
    return count;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends