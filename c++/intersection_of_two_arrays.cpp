/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

/*
 * Hash, both time and space complexity are O(n);
*/

#include "helper.h"
#include <unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num:nums2) {
            if (s.count(num)) {
                res.push_back(num);
                s.erase(num);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums1({1, 2, 2, 1});
    vector<int> nums2({2, 2});
    cout << s.intersection(nums1, nums2) << endl;

    return 0;
}
