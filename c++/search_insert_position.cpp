/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
 */

/*
 * Binary Search
*/

#include "helper.h"

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int start = 0, end = nums.size() - 1;
        while (end >= start) {
            int mid = (start + end) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return start;
    };
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << s.searchInsert(nums, target) << endl;
    target = 2;
    cout << s.searchInsert(nums, target) << endl;
    target = 7;
    cout << s.searchInsert(nums, target) << endl;
    target = 0;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}
