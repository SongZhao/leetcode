/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

/*
 * xor. Is it O(1)?
*/

#include "helper.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i< nums.size();++i) {
            res ^= nums[i];
            res ^= i;
        }
        res ^= nums[0];
        res ^= nums.size();
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 3, 4, 2};
    cout << s.missingNumber(nums) << endl;
    return 0;
}
