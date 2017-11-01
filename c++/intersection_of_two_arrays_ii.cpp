/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/*
 * Hash, both time and space complexity are O(n);
*/

#include "helper.h"

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map;
        for (int num:nums1) {
                map[num]++;
        }
        vector<int> res;
        for (int num:nums2) {
            if (map[num] > 0) {
                res.push_back(num);
                map[num]--;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums1({1});
    vector<int> nums2({1, 1});
    cout << s.intersect(nums1, nums2) << endl;

    return 0;
}
