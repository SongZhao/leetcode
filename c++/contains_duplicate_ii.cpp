/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
 such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (map.find(num) == map.end()) {
                map[num] = i;
            } else {
                if (i - map[num] <= k) {
                    return true;
                } else {
                    map[num] = i;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums({5, 3, 4, 5});
    cout << s.containsNearbyDuplicate(nums, 2) << endl;

    return 0;
}
