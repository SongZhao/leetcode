/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;

        for (int num:nums) {
            int m = abs(num) - 1;
            nums[m] = -abs(nums[m]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({4, 3, 2, 7, 8, 2, 3, 1});
    cout << s.findDisappearedNumbers(nums) << endl;
    return 0;
}
