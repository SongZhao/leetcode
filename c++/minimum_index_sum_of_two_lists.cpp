/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants
 represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between
 answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        unordered_map<string, int> dict;
        int sum = INT_MAX;
        vector<string> res;

        for (int i = 0; i < list2.size(); i++) {
            dict[list2[i]] = i + 1;
        }

        for (int i = 0; i < list1.size(); i++) {
            if (dict[list1[i]] != 0) {
                if (i + dict[list1[i]] < sum) {
                    sum = i + dict[list1[i]];
                    res.clear();
                    res.push_back(list1[i]);
                } else if (i + dict[list1[i]] == sum) {
                    res.push_back(list1[i]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> list1, list2;

    list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    list2 = {"KFC","Burger King","Tapioca Express","Shogun"};
    cout << s.findRestaurant(list1, list2) << endl;

    list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    cout << s.findRestaurant(list1, list2) << endl;

    list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    list2 = {"KFC", "Shogun", "Burger King"};
    cout << s.findRestaurant(list1, list2) << endl;

    return 0;
}
