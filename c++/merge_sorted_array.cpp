/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

/*
 * Not hard if realizing looping from back to front
*/

#include "helper.h"


class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int j = m - 1, k = n - 1;
        for (int i = m + n - 1; i >= 0; --i) {
            if (j < 0) {
                nums1[i] = nums2[k];
                --k;
                continue;
            }
            if (k < 0) {
                nums1[i] = nums1[j];
                --j;
                continue;
            }
            if (nums1[j] >= nums2[k]) {
                nums1[i] = nums1[j];
                --j;
            } else {
                nums1[i] = nums2[k];
                --k;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {0, 2, 4, 6, 8, 10};
    nums1.resize(nums1.size() + nums2.size());
    s.merge(nums1, 4, nums2, nums2.size());
    cout << nums1 << endl;
    return 0;
}
