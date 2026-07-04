class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
       
        int longestStreak{};
        for (auto i : set) {
             int seq{1};
            if (set.find(i - 1) == set.end()) {
                int x = 1;
                while (set.find(i + x) != set.end()) {
                    x++;
                    seq++;
                }

            } else {
              
                continue;
            }
            longestStreak = std::max(longestStreak, seq);
        }
        return longestStreak;
    };
};