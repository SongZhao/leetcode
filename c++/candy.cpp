/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

/*
 * greedy, two iterates two make sure the requirements are satisfied.
*/

#include "helper.h"

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) {
            return 0;
        }
        int res = 1;
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
                candies[i - 1] = candies[i] + 1;
            }
        }
        int sum = 0;
        for (int candy:candies) {
            sum += candy;
        }
        return sum;
    }
};


int main() {
    Solution s;
    vector<int> ratings({3, 2, 3});
    cout << s.candy(ratings) << endl;
    return 0;
}
