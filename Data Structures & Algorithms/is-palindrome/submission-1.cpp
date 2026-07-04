class Solution {
public:
     bool isPalindrome(string s) {
        auto left{s.begin()};
        auto right{s.end() - 1};

        while (left < right) {
            if (!std::isalnum(*left)) {
                left++;
            } else if (!std::isalnum(*right)) {
                right--;
            } else {
                if (std::tolower(*left) != std::tolower(*right)) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};
