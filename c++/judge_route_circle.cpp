/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle,
 which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are
 R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> dict;
        for(char c:moves) {
            dict[c]++;
        }

        return dict['U'] == dict['D'] && dict['L'] == dict['R'];
    }
};

int main() {
    Solution s;
    cout << s.judgeCircle("LDRRLRUULR") << endl;
    cout << s.judgeCircle("LL") << endl;
    cout << s.judgeCircle("UD") << endl;
    return 0;
}
