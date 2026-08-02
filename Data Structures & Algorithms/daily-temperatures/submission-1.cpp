class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res{};
    for(int i =0; i<temperatures.size(); i++){
        std::stack<int> c{};
        for(int j =i+1; j<temperatures.size();j++){
            if(temperatures[j]>temperatures[i]){
                c.push(temperatures[j]);
                break;
            }else if(temperatures[j]<=temperatures[i] && j==temperatures.size()-1){
               c = std::stack<int>();
                break;
            }else{
                c.push(temperatures[j]);
            }
        }
        res.push_back(c.size());
    }
    return res;
    }
};
