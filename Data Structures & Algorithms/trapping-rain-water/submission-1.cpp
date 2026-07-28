class Solution {
public:
    int trap(vector<int>& height) {
        int f = 0;
        int s = height.size() - 1;
        int total{0};
        int leftmax=0, rightmax = 0;
        while (f < s) {
            if (height[f] < height[s]) {
                if (height[f] >= leftmax) {
                    leftmax = height[f];
                } else {
                    total += leftmax - height[f];
                }
                f++;
            } else {
                if (height[s] >= rightmax) {
                    rightmax = height[s];

                } else {
                    total += rightmax - height[s];
                }
                s--;
            }
        }
        return total;
    }
};