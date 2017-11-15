/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1.
Note: Length of the array will not exceed 10,000.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int last = 1;
        int res = 0;
        for (int i = 1;i<nums.size();i++) {
            if (nums[i] > nums[i-1]) {
                last++;
            } else {
                res = max(res, last);
                last = 1;
            }
        }
        return max(res, last);
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums = {1, 3, 4, 2, 3, 4, 5};
    cout << s.findLengthOfLCIS(nums) << endl;
    nums = {1, 3, 5, 7};
    cout << s.findLengthOfLCIS(nums) << endl;
    nums = {1, 3, 5, 4, 7};
    cout << s.findLengthOfLCIS(nums) << endl;
    nums = {2, 2, 2, 2, 2};
    cout << s.findLengthOfLCIS(nums) << endl;
    return 0;
}
