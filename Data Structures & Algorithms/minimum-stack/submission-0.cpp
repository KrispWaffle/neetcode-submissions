class MinStack {
public:
    std::vector<int> stack;
    std::vector<int> minStack;
    public:
    MinStack(){

    }


    void pop(){
        stack.pop_back();
        minStack.pop_back();
    }
    void push(int val){
        stack.push_back(val);
        int newMin = minStack.empty() ? val : std::min(val, minStack.back());
        minStack.push_back(newMin);
    }
    int top(){
        return stack.back();
    }
    int getMin(){
        return minStack.back();
    }
};
