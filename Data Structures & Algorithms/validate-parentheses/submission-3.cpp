class Solution {
   public:
    bool isValid(string s) {
        std::stack<char> x;

        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                x.push(i);
            } else {
                if (x.empty()) return false;  

                char top = x.top();
                if ((i == ')' && top == '(') ||
                    (i == '}' && top == '{') ||
                    (i == ']' && top == '[')) {
                    x.pop();
                } else {
                    return false;
                }
            }
        }
        return x.empty();  
    }
};