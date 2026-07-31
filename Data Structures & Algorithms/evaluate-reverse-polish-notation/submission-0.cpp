class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    std::stack<int> x;
    
   
    for(auto &i: tokens){
        if(i != "+" && i != "-" && i != "*" && i != "/"){
           
            x.push(std::stoi(i));
        }else{
            if(i=="+"){
                int f {x.top()};
                x.pop();
                int s {x.top()};
                x.pop();
                x.push(s+f);
            }
            if(i=="-"){
                int f {x.top()};
                x.pop();
                int s {x.top()};
                x.pop();
                x.push(s-f);
            }
            if(i=="*"){
                int f {x.top()};
                x.pop();
                int s {x.top()};
                x.pop();
                x.push(s*f);
            }
            if(i=="/"){
                int f {x.top()};
                x.pop();
                int s {x.top()};
                x.pop();
                x.push(s/f);
            }
        }
    }
    return x.top();
    }
};
