/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

/*
 * Find smallest number first, then binary search
*/

#include "helper.h"

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (end - start) / 2 + start;
            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        // start = mid = index of smallest number
        if (target >= nums[start] && target <= nums[nums.size() - 1]) {
            return binarySearch(nums, target, start, nums.size() - 1);
        } else {
            return binarySearch(nums, target, 0, start);
        }
    }

    int binarySearch(const vector<int> &nums, int target, int start, int end) {
        while (start <= end) {
            int mid = (end - start) / 2 + start;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << s.search(nums, 7) << endl;
    cout << s.search(nums, 0) << endl;
    cout << s.search(nums, 4) << endl;
    cout << s.search(nums, 2) << endl;
    cout << s.search(nums, 8) << endl;
    return 0;
}
