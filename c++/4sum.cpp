/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

/*
 * Two pointers. Similar to 3sum
*/

#include <algorithm>
#include "helper.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;

        if (nums.size() < 4) {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1 ; j < nums.size() - 2; ++j) {
                int start = j + 1;
                int end = nums.size() - 1;
                while (start < end) {
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if ( sum == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[start], nums[end]});
                        ++start;
                        --end;
                        while (start < end && nums[start - 1] == nums[start]) {
                            ++start;
                        }
                        while (end > start && nums[end] == nums[end + 1]) {
                            --end;
                        }
                    } else if (sum < target) {
                        ++start;
                    } else {
                        --end;
                    }
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++i;
            }

        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2, 0, 0, 0, 0};
    int target = 0;
    cout << s.fourSum(nums, target) << endl;
    return 0;
}
