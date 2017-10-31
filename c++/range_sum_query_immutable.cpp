/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

*/

/*
 * DP, save sums
*/

#include "helper.h"

class NumArray {
public:
    NumArray(vector<int> nums) {
        if (nums.empty()) {
            return;
        }
        sums.reserve(nums.size());
        sums[0] = nums[0];
        for (int i = 1;i<nums.size();i++) {
            sums[i] = nums[i] + sums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return i == 0 ? sums[j] : sums[j] - sums[i-1];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */


int main() {
    vector<int> nums({-2, 0, 3, -5, 2, -1});
    NumArray obj(nums);
    cout << obj.sumRange(0, 2) << endl;
    cout << obj.sumRange(2, 5) << endl;
    cout << obj.sumRange(0, 5) << endl;

    return 0;
}
