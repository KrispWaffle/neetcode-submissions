class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> st;
    for (const auto& tok : tokens) {
        if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
            int rhs = st.top(); st.pop();
            int lhs = st.top(); st.pop();
            int result;
            switch (tok[0]) {
                case '+': result = lhs + rhs; break;
                case '-': result = lhs - rhs; break;
                case '*': result = lhs * rhs; break;
                case '/': result = lhs / rhs; break;
            }
            st.push(result);
        } else {
            st.push(std::stoi(tok));
        }
    }
    return st.top();
}
};
