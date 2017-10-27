/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

/*
 * reverse first n - k elements, then reverse last k elements, then reverse all elements
*/

#include "helper.h"

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 2, 3, 4, 5, 6, 7});
    s.rotate(nums, 3);
    cout << nums << endl;
    return 0;
}
