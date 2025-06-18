class Solution {
public:
    int mod = 1e9 + 7;

    long long modpow(long long x, long long n) {
        if (n == 0) return 1;

        long long ans = modpow(x, n / 2);
        ans = (ans * ans) % mod;

        if (n % 2 == 1) {
            ans = (ans * x) % mod;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // Even indices -> 5 choices
        long long odd = n / 2;        // Odd indices -> 4 choices

        long long epl = modpow(5, even); // 5^even % mod
        long long opl = modpow(4, odd);  // 4^odd % mod

        return (int)((epl * opl) % mod);
    }
};
