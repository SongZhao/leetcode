/*
Given an array of integers, find if the array contains any duplicates.
 Your function should return true if any value appears at least twice in the array,
 and it should return false if every element is distinct.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (int num:nums) {
            if (map.find(num) == map.end()) {
                map[num] = true;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 3, 5, 5});
    cout << s.containsDuplicate(nums) << endl;

    return 0;
}
