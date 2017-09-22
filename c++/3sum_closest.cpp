/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*
 * Two pointers. Similar to 3sum, but no need to avoid duplicate
*/

#include "helper.h"
#include <limits>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = std::numeric_limits<int>::max();
        int minDist = res;
        std:sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum =nums[i] + nums[start] + nums[end];
                if (sum < target) {
                    if (abs(sum - target) < minDist) {
                        res = sum;
                        minDist = abs(sum - target);
                    }
                    ++start;
                } else if (sum > target) {
                    if (abs(sum - target) < minDist) {
                        res = sum;
                        minDist = abs(sum - target);
                    }
                    --end;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << s.threeSumClosest(nums, target) << endl;
    return 0;
}
