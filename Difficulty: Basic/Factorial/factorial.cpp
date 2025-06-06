class Solution {
  public:
    void helper(int n, int &fact) {
        if (n == 0) return;
        helper(n - 1, fact);
        fact *= n;
    }

    int factorial(int n) {
        int fact = 1;
        helper(n, fact);
        return fact;
    }
};
