class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& arr) {
        std::vector<int> res(arr.size());
        int suffix{1};
        int prefix{1};
        for (size_t i = 0; i < arr.size(); ++i) {
            res[i] = prefix;
            prefix *= arr[i];
        }

        for (size_t i = arr.size(); i > 0; i--) {
            res[i - 1] *= suffix;
            suffix *= arr[i - 1];
        }
        return res;
    }
};
