class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& x) {
        std::vector<std::vector<int>> lists{};
        std::sort(x.begin(), x.end());
        for (auto i{0}; i < x.size(); i++) {
            if (i != 0 && x[i] == x[i - 1]) {
                continue;
            }
            int left{i + 1};
            auto right{x.size() - 1};
            int target = -x[i];
            while (left < right) {
                if (x[left] + x[right] == target) {
                    lists.push_back({x[i], x[left], x[right]});
                    right--;
                    left++;
                    while (left < right && x[left] == x[left - 1]) {
                        left++;
                    }
                    while (right > left && x[right] == x[right + 1]) {
                        right--;
                    }
                } else if (x[left] + x[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return lists;
    }
};