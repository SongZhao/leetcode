/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
 */

/*
 * greedy, total < 0 means cannot traval around the circuit, sum < 0 means cannot start from [0,i]
*/

#include "helper.h"

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int cur = 0, sum = 0, total = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            total += sum;
            if (sum < 0) {
                cur = i + 1;
                sum = 0;
            }
        }
        return total >= 0 ? cur : -1;
    }
};


int main() {
    Solution s;
    vector<int> gas({1, 2, 3, 4, 5});
    vector<int> cost({1, 2, 3, 4, 5});
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
