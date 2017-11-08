/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses
 could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius
 standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.

*/

/*
 * count + 1 if one's neighbour is 0 or edge
 */

#include "helper.h"

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        if (heaters.empty() || houses.empty()) {
            return 0;
        }

        int res = 0;
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());

        int j = 0;
        for (int house:houses) {
            while (j < heaters.size() - 1 && (abs(house - heaters[j + 1]) <= abs(house - heaters[j]))) {
                j++;
            }
            res = max(res, abs(house - heaters[j]));
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> houses, heaters;
    houses = {1, 2, 3};
    heaters = {2};
    cout << s.findRadius(houses, heaters) << endl;
    houses = {1, 2, 3, 4};
    heaters = {1, 4};
    cout << s.findRadius(houses, heaters) << endl;

    return 0;
}
