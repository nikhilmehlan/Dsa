class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int cnt=0;
        for(auto it:isPrime)
        if(it){
            cnt++;
        }
        return cnt;
    }
};