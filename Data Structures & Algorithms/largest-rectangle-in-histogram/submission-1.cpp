class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int currBest{0};
        std::stack<int> s;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!s.empty() && heights[s.top()] > heights[i]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                currBest = std::max(currBest, height * width);
            }
            s.push(i);
        }
        int n = heights.size();
        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? n : n - s.top() - 1;
            currBest = std::max(currBest, height * width);
        }
        return currBest;
    }
};
