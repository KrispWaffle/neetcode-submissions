class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int best = 0;
        int maxFreq = 0;

        std::array<int, 26> arr{};
        while (right < s.size()) {
            arr[s[right] - 'A']++;
            maxFreq = max(maxFreq, arr[s[right]-'A']);

            while (!(((right - left + 1) - maxFreq) <= k)) {
                
                arr[s[left] - 'A']--;
                left++;
            }

            best = std::max(best, right - left + 1);
            right++;
        }
        return best;
    }
};
