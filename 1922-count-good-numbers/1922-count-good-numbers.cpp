class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long modPow(long long x, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n % 2 == 1) { // If n is odd, multiply x with the result
                ans = (ans * x) % MOD;
            }
            x = (x * x) % MOD; // Square the base
            n = n / 2;         // Reduce n by half
        }
        return ans % MOD;
    }
    
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // Number of even-indexed positions
        long long odd = n / 2;        // Number of odd-indexed positions
        
        long long first = modPow(5, even) % MOD; // 5 choices for even positions
        long long second = modPow(4, odd) % MOD; // 4 choices for odd positions
        
        return (int)(first * second % MOD);      // Final result under modulo
    }
};
