/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
 */

/*
 * greedy
*/

#include "helper.h"

class Solution {
public:
    int jump(vector<int> &nums) {
        int res = 0, maxJump = 0, i = 0;
        while (maxJump < nums.size() - 1) {
            int temp = maxJump;
            while (i <= temp) {
                maxJump = max(maxJump, i + nums[i]);
                i++;
            }
            res++;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums({2, 3, 1, 1, 4});
    cout << s.jump(nums) << endl;
    return 0;
}
