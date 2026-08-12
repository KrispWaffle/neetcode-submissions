
constexpr long long divCeil(long long a, long long b) {
    return (a + b - 1) / b;
}
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid{left + (right - left) / 2};
            long long hours{0};
            for (int p : piles) {
                hours += divCeil(p, mid);
            }
            if (hours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
