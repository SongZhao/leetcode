/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
 * From right to left, first find first decreasing element a[i], then find the number a[j] that is just larger than a[i],
 * then swap a[i] and a[j], and reverse the following numbers
*/


#include "helper.h"

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums = {5,4,7,5,3,2};
    s.nextPermutation(nums);
    cout << nums << endl;
    nums = {2, 3, 1};
    s.nextPermutation(nums);
    cout << nums << endl;
    nums = {1, 2, 3};
    s.nextPermutation(nums);
    cout << nums << endl;
    nums = {3, 2, 1};
    s.nextPermutation(nums);
    cout << nums << endl;
    nums = {1, 1, 5};
    s.nextPermutation(nums);
    cout << nums << endl;

    return 0;
}
