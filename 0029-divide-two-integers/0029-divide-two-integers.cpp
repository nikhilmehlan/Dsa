class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        // Handle signs using XOR
        bool sign = (dividend > 0) == (divisor > 0);

        // Convert to long to prevent overflow, take absolute values
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quotient = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += 1LL << cnt;
            n -= d << cnt;
        }

        if (!sign) quotient = -quotient;

        // Clamp to 32-bit signed integer range
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return quotient;
    }
};
