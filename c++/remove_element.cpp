/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/

/*
Quite simple one. Time complexity O(n)
*/

#include "helper.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

int main() {
    Solution s;
    const int arr[] = {3, 2, 2, 3};
    const int val = 3;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << s.removeElement(v, val) << endl;
    cout << v << endl;
    return 0;
}
