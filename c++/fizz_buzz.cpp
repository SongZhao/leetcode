/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */

/*
 * max len is even count + (odd count - 1) + hasOddCount
*/

#include "helper.h"

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            string tmp;
            if (i % 3 == 0) {
                tmp += "Fizz";
            }
            if (i % 5 == 0) {
                tmp += "Buzz";
            }
            if (i % 3 != 0 && i % 5 != 0) {
                tmp = to_string(i);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.fizzBuzz(15) << endl;

    return 0;
}
