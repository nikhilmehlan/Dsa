//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {
    // Step 1: Create and initialize the SPF (Smallest Prime Factor) array
    vector<int> spf(N + 1);
    for (int i = 1; i <= N; i++) {
        spf[i] = i;
    }

    // Step 2: Sieve of Eratosthenes to populate the SPF array
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // Check if i is a prime number
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) { // Update SPF only if it hasn't been updated yet
                    spf[j] = i;
                }
            }
        }
    }

    // Step 3: Find the prime factorization using the SPF array
    vector<int> ans;
    while (N != 1) {
        int prime = spf[N];
        while (N % prime == 0) {
        ans.push_back(prime);
            N = N / prime; // Divide N by the current prime factor
        }
    }

    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends