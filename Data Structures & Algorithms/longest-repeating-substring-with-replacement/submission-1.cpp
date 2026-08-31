class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int best = 0;

        std::array<int, 26> arr{};
        while (right < s.size()) {
            int maxFreq = 0;
            arr[s[right] - 'A']++;
            for (int i = 0; i < 26; i++) {
                maxFreq = std::max(maxFreq, arr[i]);
            }

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
