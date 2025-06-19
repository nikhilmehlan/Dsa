class Solution {
public:
    vector<bool> check(int n) {
        vector<bool> isPrime(n, true);  // n means range [0, n-1]
        if (n > 0) isPrime[0] = false;
        if (n > 1) isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return isPrime;
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime = check(n);
        int cnt = 0;
        for (bool it : isPrime) {
            if (it) cnt++;
        }
        return cnt;
    }
};
