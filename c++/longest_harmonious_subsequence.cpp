/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.

*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int findLHS(vector<int> &nums) {
        map<int, int> dict;
        for(int num:nums) {
            dict[num]++;
        }
        int i = 0, res = 0;
        pair<int, int> last;
        for (auto &it:dict) {
            if (last.second == 0) {
                last.first = it.first;
                last.second = it.second;
                continue;
            }
            if (it.first - last.first ==1) {
                res = max(res, it.second + last.second);
            }
            last.first = it.first;
            last.second = it.second;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 3, 2, 2, 5, 2, 3, 7});
    cout << s.findLHS(nums) << endl;

    return 0;
}
