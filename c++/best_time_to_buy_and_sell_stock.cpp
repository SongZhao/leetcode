/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
 */

/*
 * simple one, keep track of min price and max profit
*/

#include "helper.h"
#include <limits>

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min = std::numeric_limits<int>::max();
        int profit = 0;
        for (int price: prices) {
            if (price < min) {
                min = price;
            }
            profit = std::max(profit, price - min);
        }
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> prices({7, 1, 5, 3, 6, 4});
    cout << s.maxProfit(prices) << endl;
    return 0;
}
