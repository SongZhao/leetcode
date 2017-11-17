/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/

/*
 * solution is intuitive, data structure is complicated
*/

#include "helper.h"

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        map<int, pair<int, pair<int, int>>> dict; //<number, <count, <start, end>>>
        pair<int, int> count; // <count, index>

        for (int i = 0; i < nums.size(); i++) {
            dict[nums[i]].first++;
            if (dict[nums[i]].first == 1) {
                dict[nums[i]].second.first = i;
            }
            dict[nums[i]].second.second = i;
            if (dict[nums[i]].first > count.first) {
                count.first = dict[nums[i]].first;
                count.second = nums[i];
            } else if (dict[nums[i]].first == count.first) {
                if (dict[count.second].second.second - dict[count.second].second.first >
                    dict[nums[i]].second.second - dict[nums[i]].second.first) {
                    count.first = dict[nums[i]].first;
                    count.second = nums[i];
                }
            }
        }
        return dict[count.second].second.second - dict[count.second].second.first + 1;
    }
};


int main() {
    Solution s;
    vector<int> nums;
    nums = {1, 2, 2, 3, 1};
    cout << s.findShortestSubArray(nums) << endl;
    nums = {1, 2, 2, 3, 1, 4, 2};
    cout << s.findShortestSubArray(nums) << endl;
    nums = {2, 1, 1, 2, 1, 3, 3, 3, 1, 3, 1, 3, 2};
    cout << s.findShortestSubArray(nums) << endl;

    return 0;
}
