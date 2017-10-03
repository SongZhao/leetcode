/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

/*
 *
*/

#include "helper.h"
#include <limits>


class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res =  std::numeric_limits<int>::min();
        int sum = 0;

        for (int num : nums) {
            sum += num;
            res = max(sum, res);
            if (sum < 0) {
                sum = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
