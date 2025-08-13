class Solution {
public:
    bool isPowerOfThree(int n) {
       const int MAX_POW3 = 1162261467; // 3^19
    return n > 0 && (MAX_POW3 % n == 0);
    }
};