/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 */

/*
 * Two binary searches
*/

#include "helper.h"

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) {
            return vector<int>({-1, -1});
        }
        vector<int> res;
        int start = 0, end = nums.size() - 1;
        while (end >= start) {
            int mid = (start + end) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (start < nums.size() && nums[start] == target) {
            res.push_back(start);
            end = nums.size() - 1;
            while (end >= start) {
                int mid = (start + end) / 2;
                if (nums[mid] <= target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            res.push_back(end);
        } else {
            return vector<int>({-1, -1});
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    cout << s.searchRange(nums, target) << endl;
    nums = {0, 0, 2, 3, 4, 4, 4, 5};
    target = 5;
    cout << s.searchRange(nums, target) << endl;
    return 0;
}
