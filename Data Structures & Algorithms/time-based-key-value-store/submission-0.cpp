class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;
    

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = store[key].size()-1;
        std::string best{};
        while(left<=right){
            int mid =  left + (right - left) / 2;
            if(store[key][mid].first == timestamp){
                return store[key][mid].second;
            }else if(store[key][mid].first > timestamp){
                right = mid-1;
            }else{
                best = store[key][mid].second;
                left = mid+1;
            }
        }
        return best;
    }
};
