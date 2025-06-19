class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Your code here
        return (n &(1<<k));
    }
};