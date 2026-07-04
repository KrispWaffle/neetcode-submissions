class Solution {
public:
    bool isPalindrome(string s) {
        std::string newString{};
        for (auto& i : s) {
            if (std::isalnum(static_cast<unsigned char>(i))) {
                newString += std::tolower(i);
            }
        }
        std::string c(newString.rbegin(), newString.rend());
        if (newString == c) {
            return true;
        } else {
            return false;
        }
    }
};
