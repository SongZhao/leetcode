/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/

/*
 * 
*/

#include "helper.h"
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (char c:s) {
            if (c == '(' || c == '[' || c == '{') {
                parentheses.push(c);
            } else {
                if (parentheses.empty()) {
                    return false;
                }
                if (c == ')'){
                    if (parentheses.top() != '(') {
                        return false;
                    }
                    parentheses.pop();
                } else if (c == ']'){
                    if (parentheses.top() != '[') {
                        return false;
                    }
                    parentheses.pop();
                } else if (c == '}'){
                    if (parentheses.top() != '{') {
                        return false;
                    }
                    parentheses.pop();
                }
            }
        }
        return parentheses.empty();
    }
};

int main() {
    Solution s;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("()") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("]") << endl;
    return 0;
}
