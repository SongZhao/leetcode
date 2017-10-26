/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num:nums) {
            if (map.find(num) != map.end()) {
                map[num]++;
            } else {
                map[num] = 1;
            }
            if (map[num] > nums.size() / 2) {
                return num;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 2, 2});
    cout << s.majorityElement(nums) << endl;
    return 0;
}
