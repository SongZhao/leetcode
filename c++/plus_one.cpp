/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

*/

/*
 * Straightforward. Don't forget to check if inserting 1 to beginning of vector is needed after the loop
*/

#include "helper.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] + c == 10) {
                digits[i] = 0;
                c = 1;
            } else {
                digits[i] = digits[i] + c;
                c = 0;
            }
        }
        if (c == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution s;
    const int arr[] = {9};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << s.plusOne(v) << endl;
    return 0;
}
