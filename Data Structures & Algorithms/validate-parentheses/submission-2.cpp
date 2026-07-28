class Solution {
   public:
    bool isValid(string s) {
        std::vector<char> x;

        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                x.push_back(i);
            } else {
                if (x.empty()) return false;  

                char top = x.back();
                if ((i == ')' && top == '(') ||
                    (i == '}' && top == '{') ||
                    (i == ']' && top == '[')) {
                    x.pop_back();
                } else {
                    return false;
                }
            }
        }
        return x.empty();  
    }
};