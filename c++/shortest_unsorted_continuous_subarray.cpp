/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

/*
 *
*/

#include "helper.h"
#include <stack>

// Time O(nlogn), Space O(n)
/*class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end());
        int left = nums.size(), right = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums2[i]) {
                left = min(left, i);
                right = max(right, i);
            }
        }

        return right >= left ? right - left + 1 : 0;
    }
};*/

// Time O(n), Space O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        stack<int> s;
        int left = nums.size(), right = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                left = min(left, s.top());
                s.pop();
            }
            s.push(i);
        }
        s = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                right = max(right, s.top());
                s.pop();
            }
            s.push(i);
        }
        return right >= left ? right - left + 1 : 0;
    }
};

int main() {
    Solution s;
    vector<int> candies({2, 6, 4, 8, 10, 9, 15});
    cout << s.findUnsortedSubarray(candies) << endl;

    return 0;
}
