

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int low = 0;
        int high = nums1.size();
        int leftsize = (nums1.size() + nums2.size() + 1) / 2;
        if (nums1.size() > nums2.size()) {
    return findMedianSortedArrays(nums2, nums1);
}
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = leftsize - i;

            int Aleft = (i == 0) ? std::numeric_limits<int>::min() : nums1[i - 1];

            int Aright = (i == nums1.size()) ? std::numeric_limits<int>::max() : nums1[i];

            int Bleft = (j == 0) ? std::numeric_limits<int>::min() : nums2[j - 1];

            int Bright = (j == nums2.size()) ? std::numeric_limits<int>::max() : nums2[j];

            if (Aleft > Bright) {
                high = i - 1;
            } else if (Bleft > Aright) {
                low = i + 1;
            } else {
                if ((nums1.size() + nums2.size()) % 2 == 0) {
                    int largestLeft = std::max(Aleft, Bleft);
                    int smallestRight = std::min(Aright, Bright);

                    return (largestLeft + smallestRight) / 2.0;
                } else {
                    return std::max(Aleft, Bleft);
                }
            }
        }
        return -1;
    }
};
