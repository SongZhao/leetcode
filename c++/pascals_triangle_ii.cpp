/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

/*
 * kind of tricky..
*/

#include "helper.h"


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vals;
        vals.resize(rowIndex + 1, 1);
        for (int i = 0; i < rowIndex + 1; ++i) {
            for (int j = i - 1; j > 0; --j) {
                vals[j] = vals[j] + vals[j - 1];
            }
        }
        return vals;
    }
};

int main() {
    Solution s;
    int rowIndex = 4;
    cout << s.getRow(rowIndex) << endl;
    return 0;
}
