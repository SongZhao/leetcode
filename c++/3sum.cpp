/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
 * Two pointers. Avoid duplicates in both outer and inner loop
*/

#include <algorithm>
#include "helper.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;

        if (nums.size() < 3) {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                if (nums[i] + nums[start] + nums[end] == 0) {
                    res.push_back(vector<int>{nums[i], nums[start], nums[end]});
                    ++start;
                    --end;
                    while (start < end && nums[start - 1] == nums[start]) {
                        ++start;
                    }
                    while (end > start && nums[end] == nums[end + 1]) {
                        --end;
                    }
                } else if (nums[i] + nums[start] + nums[end] < 0) {
                    ++start;
                } else {
                    --end;
                }
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                    ++i;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-2, 0, 1, 1, 2, 0, 0, 0, 0};
    cout << s.threeSum(nums) << endl;
    return 0;
}
