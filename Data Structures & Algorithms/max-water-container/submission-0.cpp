class Solution {
public:
    int maxArea(vector<int>& height) {
        int left{0};
        int right{static_cast<int>(height.size() - 1)};
        int max{0};
        while (left < right) {
            int water = std::abs((right - left) *
                                 std::min(height[left], height[right]));
            if (water > max) {
                max = water;
            }
            if (height[left] > height[right]) {
                right--;
            } else if (height[right] > height[left]) {
                left++;
            } else {
                right--;
                left++;
            }
        }
        return max;
    }
};