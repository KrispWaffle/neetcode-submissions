class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;
    

    TimeMap() {
        
    }
    
    void set(const string& key, string value, int timestamp) {
    store[key].emplace_back(timestamp, std::move(value));
}

    
    string get(const string& key, int timestamp) {
    auto it = store.find(key);
    if (it == store.end()) return "";
    const auto& entries = it->second;

    auto pos = std::upper_bound(
        entries.begin(), entries.end(), timestamp,
        [](int ts, const auto& p) { return ts < p.first; }
    );

    if (pos == entries.begin()) return "";
    return std::prev(pos)->second;
}
};
