class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        cars.reserve(position.size());

        for (size_t i = 0; i < position.size(); ++i) {
            cars.emplace_back(position[i], speed[i]);
        }
        std::sort(cars.begin(), cars.end(), std::greater<>());

        std::stack<double> times;
        for (size_t i = 0; i < cars.size(); i++) {
            double time = double(target - cars[i].first) / cars[i].second;
            if (!times.empty() && time <= times.top()) {
                continue;
            } else {
                times.push(time);
            }
        }
        return times.size();
    }
};
