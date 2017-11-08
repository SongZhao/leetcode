/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
 Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist,
 output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/

/*
 * can also use stack and hash
*/

#include "helper.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        vector<int> res;
        for (int num1:findNums) {
            bool found = false;
            int i = 0;
            while (i<nums.size()) {
                int num2 = nums[i];
                if (num1 == num2) {
                    found = true;
                }
                if (found && num2 > num1) {
                    res.push_back(num2);
                    break;
                }
                i++;
            }
            if (i == nums.size()) {
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> findNums, nums;
    findNums = {4, 1, 2};
    nums = {1, 3, 4, 2};
    cout << s.nextGreaterElement(findNums, nums) << endl;
    findNums = {2, 4};
    nums = {1, 2, 3, 4};
    cout << s.nextGreaterElement(findNums, nums) << endl;

    return 0;
}
