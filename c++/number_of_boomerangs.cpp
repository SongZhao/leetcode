/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that
 the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the
 range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int res = 0;
        unordered_map<int, int> dict;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) {
                    continue;
                }
                int dist = (points[i].second - points[j].second) * (points[i].second - points[j].second) +
                           (points[i].first - points[j].first) * (points[i].first - points[j].first);
                dict[dist]++;
            }
            for (auto &it: dict) {
                res += it.second * (it.second - 1);
            }
            dict.clear();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<pair<int, int>> points({{0, 0},
                                   {1, 0},
                                   {2, 0}});
    cout << s.numberOfBoomerangs(points) << endl;
    return 0;
}
