class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int width = right - left;
            maxWater = max(maxWater, h * width);

            // Move the pointer with the shorter line
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};
