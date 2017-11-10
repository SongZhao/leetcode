/*
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array.
 Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and
 their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].
*/

/*
 *
*/

#include "helper.h"
#include <set>
#include <map>

/*
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        set<pair<int, int>> st;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    if (st.find(make_pair(nums[j], nums[i])) == st.end()) {
                        st.insert(make_pair(nums[i], nums[j]));
                    }

                }
            }
        }
        return st.size();
    }
};
*/

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (k < 0 || nums.empty()) {
            return 0;
        }
        int res = 0;
        map<int, int> mp;
        for (int num:nums) {
            mp[num]++;
        }

        for (auto &it:mp) {
            if (k == 0) {
                if (it.second > 1) {
                    res++;
                }
            } else {
                if (mp.find(it.first + k) != mp.end()) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums = {1, 1, 1, 2, 1};
    cout << s.findPairs(nums, 1) << endl;
    nums = {3, 1, 4, 1, 5};
    cout << s.findPairs(nums, 2) << endl;
    nums = {1, 2, 3, 4, 5};
    cout << s.findPairs(nums, 1) << endl;
    nums = {1, 3, 1, 5, 4};
    cout << s.findPairs(nums, 0) << endl;
    return 0;
}
