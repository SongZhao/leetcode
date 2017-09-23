/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 */

/*
 * Binary Search
*/

#include "helper.h"

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int start = 0, end = nums.size() - 1, mid = 0;
        while (end >= start) {
            mid = (start + end) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            } else if (mid > 0 && nums[mid] < nums[mid - 1]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return mid;
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}
