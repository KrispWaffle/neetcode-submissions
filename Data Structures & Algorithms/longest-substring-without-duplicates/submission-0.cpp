class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen{};
        int n = s.size();
        int maxLength = 0, left = 0;
    

        for (int right = 0; right < s.size(); right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
