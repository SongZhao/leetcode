/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

/**
 * Two pointers. Add count
 */

#include "helper.h"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int j = 0, count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j]){
                nums[++j] = nums[i];
                count = 0;
            } else {
                count++;
                if ( count < 2) {
                    nums[++j] = nums[i];
                }
            }
        }
        return j + 1;
    }
};

int main() {
    Solution s;
    const int arr[] = {1, 1, 1, 1, 2, 2, 2, 2, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << s.removeDuplicates(v) << endl;
    cout << v << endl;
    return 0;
}
