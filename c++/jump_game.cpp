/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 */

/*
 * greedy, use a variable to keep track of max jump index so far and return false if current index is larger than max jump index.
*/

#include "helper.h"

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int maxJump = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxJump) {
                return false;
            }
            maxJump = max(maxJump, i + nums[i]);
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<int> nums({2, 3, 1, 1, 4});
    cout << s.canJump(nums) << endl;
    nums = {3, 2, 1, 0, 4};
    cout << s.canJump(nums) << endl;
    return 0;
}
