/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    unordered_map<int, int> map;
    int numTrees(int n) {
        if (n < 2) {
            map[n] = 1;
            return 1;
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int left,right;
            if (map.count(i - 1) == 0) {
                left = numTrees(i - 1);
                map[i - 1] = left;
            } else {
                left = map[i-1];
            }
            if (map.count(n - i) == 0) {
                right = numTrees(n - i);
                map[n - i] = right;
            } else {
                right = map[n - i];
            }
            res += left * right;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.numTrees(4) << endl;

    return 0;
}
