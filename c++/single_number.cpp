/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

/*
 * Use xor
*/

#include "helper.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num:nums) {
            res ^= num;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({7, 2, 3, 4, 4, 3, 2});
    cout << s.singleNumber(nums) << endl;
    return 0;
}
