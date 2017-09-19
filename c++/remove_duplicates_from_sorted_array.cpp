/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

/**
 * Two pointers. Straightforward
 */

#include "helper.h"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int j = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};

int main() {
    Solution s;
    const int arr[] = {1, 1, 2, 2, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << s.removeDuplicates(v) << endl;
    cout << v << endl;
    return 0;
}
